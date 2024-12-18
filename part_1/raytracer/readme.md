# Raytracer

В этой задаче вам предстоит написать игрушечный рейтрейсер, с помощью которого можно
рендерить простейшие сцены.

Основная часть задачи будет описана на семинаре, здесь приведены детали, не вошедшие в запись, плюс небольшое резюме рассказанного.

Для сдачи этого домашнего задания вы также должны сдать 3 вспомогательные задачи:

* [raytracer-geom](../raytracer-geom)
* [raytracer-reader](../raytracer-reader)
* [raytracer-debug](../raytracer-debug)

При сдаче этой задачи вы можете не копировать код из вспомогательных задач --- он будет доступен с помощью инклюдов как при локальной разработке, так и в тестирующей системе. Чтобы это работало используйте синтаксис `#include "header.h"`.

Здесь вам необходимо реализовать функцию
```c++
Image Render(const std::filesystem::path& path, const CameraOptions& camera_options, const RenderOptions& render_options);
```

В отличие от `raytracer-debug`, в этой задаче используется режим `RenderMode::kFull`.

Эта функция должна быть реализована в файле `raytracer.h`.
Обратите внимание, что помимо этого вы можете создавать
произвольное число `.h` файлов в директории задачи.
Все они будут учитываться при проверке решения на сервере.

## Настройка окружения

На ubuntu установите следующие библиотеки:
```
sudo apt-get install libpng-dev
```

Для Mac:
```
brew install libpng
```

## Тесты

Каждый тест представляет из себя сравнение результата вашего рендера и авторского на одних и тех же входных данных. Обратите внимание, что в каждом тесте вы можете добавить в `CheckImage` дополнительный аргумент - путь до .png файла, куда будет
записан результат вашего рендера. Вы можете как угодно менять файл с тестами -
он не учитывается при тестировании вашего решения.

Вы также можете использовать фильтры, чтобы запустить только нужный вам тест. Например
```bash
./test_raytracer_asan "Box with spheres"
```

Ваше решение будет проверяться на двух типах сборки: `Asan` и `RelWithDebInfo`.
При чём некоторые тесты не будут запускаться в `Asan` сборке.

В силу структуры тестов у некоторых может возникнуть соблазн считать авторский ответ и выдать его как свой.
Авторы таких "решений" получат неуд. за весь курс.

## Освещение

Освещенность в точке $`p`$ некоторого объекта задается формулой
```math
I_p = I_{base}(p) + I_{comp}(p),
```

где
```math
I_{base}(p) = K_a + K_e + al_0 \sum_{m \in lights} (K_d I_d(p, m) + K_s I_s(p, m))
```

Сумма берется по всем источникам света, которые видны из точки $`p`$ (все объекты считаются непрозрачными при проверке на видимость). $`I_d`$ и $`I_s`$
это соответственно diffuse и specular составляющие освещения из модели Фонга (https://en.wikipedia.org/wiki/Phong_reflection_model).

$`I_{comp}`$ считается так:
```math
I_{comp}(p) = al_1 I_{reflect}(p) + al_2 I_{refract}(p)
```

Здесь $`I_{refract}(p)`$ - освещенность от преломленного в точке $`p`$ луча, а $`I_{reflect}(p)`$ - освещенность
отраженного в $`p`$ луча. Обратите внимание, что отраженный луч не нужно считать, если сейчас трассируются
луч внутри объекта (в нашем случае если трассируется преломленный луч внутри полупрозрачной сферы).

## Постпроцессинг

### Tone Mapping

Когда рендеринг завершен, и для каждой точки известна тройка `v = (r, g, b)`, нужно произвести ряд действий.
Основная проблема состоит в том, что эти значения могут быть больше 1, а чтобы сохранить изображение нужно иметь значения в диапазоне `[0, 1]`.
Процедура приведения этих значений в диапазон `[0, 1]` обычно называется [tone mapping](https://en.wikipedia.org/wiki/Tone_mapping), и в нашем задании ее нужно сделать следующим
образом:

* Пусть наибольшее значение среди всех `(r, g, b)` по всем точкам изображения равно `C` (это скаляр, т.е. максимум берется и по самим тройкам).
* Тогда вектор $`V_{in} = (r, g, b)`$ нужно преобразовать в выходной $`V_{out}`$ по правилу (все операции выполняются поэлементно)
```math
V_{out} = \dfrac{V_{in}\left(1 + \dfrac{V_{in}}{C^2}\right)}{1 + V_{in}}
```

### Гамма коррекция

Теперь когда все значения лежат в диапазоне `[0, 1]` осталось сделать последний шаг. Все вычисления при рендеринге выполнялись в линейном RGB,
но при сохранении изображений линейный RGB практически никогда не используется, т.к. в этом случае нужно выделять больше 8 бит на канал (например
иметь значения в диапазоне `[0, 2^16)`), чтобы изображение выглядело нормально. Пусть значение $`V_{out}`$ получено с предыдущего шага.
Тогда в итоговое изображение нужно записать
```math
V_{gamma} = V_{out}^{\frac{1}{2.2}}
```

Обратите внимание, что класс `Image`, через который происходит запись изображений, ожидает целочисленные rgb, т.е. полученное $`V_{gamma}`$ нужно
домножить на 255 и привести в целые числа.

Подробнее можно прочитать на вики (https://en.wikipedia.org/wiki/Gamma_correction) если интересно.

## Бонус

У этой задачи есть бонусная подзадача:

* [ускорение рендеринга](../raytracer-b2)
