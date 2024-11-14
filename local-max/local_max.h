#pragma once

#include <stdexcept>

template <class Iterator>
Iterator LocalMax(Iterator first, Iterator last) {
    if (first == last) {
        return last;
    }
    if (std::next(first) == last) {
        return first;
    }
    if (*std::next(first) < *first) {
        return first;
    }
    for (auto it = std::next(first); std::next(it) != last; ++it) {
        if (*std::prev(it) < *it && *std::next(it) < *it) {
            return it;
        }
    }
    if (*std::prev(std::prev(last)) < *std::prev(last)) {
        return std::prev(last);
    }
    return last;
}
