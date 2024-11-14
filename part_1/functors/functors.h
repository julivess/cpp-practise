#pragma once

#include <cstddef>
#include <iostream>
#include <vector>
#include <algorithm>

template <class Functor>
class ReverseUnaryFunctor {
public:
    ReverseUnaryFunctor(Functor func) : func_(func) {
    }

    template <class T>
    bool operator()(const T& arg) const {
        return !func_(arg);
    }

private:
    Functor func_;
};

template <class Functor>
class ReverseBinaryFunctor {
public:
    ReverseBinaryFunctor(Functor func) : func_(func) {
    }

    template <class T>
    bool operator()(const T& arg1, const T& arg2) const {
        return func_(arg2, arg1);
    }

private:
    Functor func_;
};

auto MakeReverseUnaryFunctor(auto functor) {
    return ReverseUnaryFunctor{functor};
}

auto MakeReverseBinaryFunctor(auto functor) {
    return ReverseBinaryFunctor{functor};
}

template <class Iterator>
class ComparisonsCounter {
public:
    ComparisonsCounter(size_t& cnt) : count_(cnt) {
    }
    template <class T>
    bool operator()(const T& a, const T& b) const {
        ++count_;
        return a < b;
    }

private:
    size_t& count_;
};

template <class Iterator>
size_t ComparisonsCount(Iterator first, Iterator last) {
    size_t count = 0;
    ComparisonsCounter<Iterator> counter(count);
    std::sort(first, last, counter);
    return count;
}
