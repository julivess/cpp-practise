#pragma once

#include <stdexcept>
#include <vector>
#include <cstddef>

void Reverse(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    while ((begin != end) && (begin != --end)) {
        std::swap(*begin++, *end);
    }
}
void Rotate(std::vector<int>* data, size_t shift) {
    size_t n = data->size();
    if (n == 0 || shift == 0) {
        return;
    }
    shift = shift % n;
    if (shift == 0) {
        return;
    }
    Reverse(data->begin(), data->end());
    Reverse(data->begin(), data->begin() + n - shift);
    Reverse(data->begin() + n - shift, data->end());
}