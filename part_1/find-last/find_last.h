#pragma once

#include <stdexcept>

template <class Iterator, class T>
Iterator FindLast(Iterator first, Iterator last, const T& value) {
    if (first == last) {
        return last;
    }
    --last;
    Iterator it = last;
    while (it != first) {
        if (*it == value) {
            return it;
        }
        --it;
    }
    if (*first == value) {
        return first;
    }
    return ++last;
}
