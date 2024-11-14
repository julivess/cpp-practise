#pragma once

#include <stdexcept>
#include <vector>

struct Sum {
    template <class T>
    T operator()(const T& a, const T& b) const {
        return a + b;
    }
};

struct Prod {
    template <class T>
    T operator()(const T& a, const T& b) const {
        return a * b;
    }
};

struct Concat {
    template <class T>
    std::vector<T> operator()(const std::vector<T>& a, const std::vector<T>& b) const {
        std::vector<T> res = a;
        res.insert(res.end(), b.begin(), b.end());
        return res;
    }
};

class Length {
public:
    Length(size_t* len) : len_(len) {
    }
    template <class T>
    T operator()(T, T) {
        *len_ = *len_ + 1;
        return T{};
    }

private:
    size_t* len_;
};

template <class Iterator, class T, class BinaryOp>
T Fold(Iterator first, Iterator last, T init, BinaryOp func) {
    if (first == last) {
        return init;
    }
    T to = func(init, *first);
    for (auto it = std::next(first); it != last; ++it) {
        to = func(to, *it);
    }
    return to;
}
