#pragma once

#include <stdexcept>

template <class Iterator, class Predicate>
Iterator Partition(Iterator first, Iterator last, Predicate pred) {
    if (first == last) {
        return last;
    }
    auto iter = first;
    for (auto it = first; it != last; ++it) {
        if (pred(*it)) {
            if (iter != it) {
                std::iter_swap(iter, it);
            }
            ++iter;
        }
    }
    return iter;
}
