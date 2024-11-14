#pragma once

#include <stdexcept>

int BinPow(int a, int64_t b, int c) {

    int64_t cmp = a;

    if (cmp == 1) {
        return 1;
    }

    if (b == 0) {
        return 1;
    }

    if (b % 2 == 0) {
        return static_cast<int>(BinPow(cmp * cmp % c, b / 2, c) % c);
    }

    return static_cast<int>(cmp % c * BinPow(cmp % c, b - 1, c) % c);
}