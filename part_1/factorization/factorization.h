#pragma once

#include <utility>
#include <vector>
#include <cstdint>
#include <stdexcept>
#include <math.h>

std::vector<std::pair<int64_t, int>> Factorize(int64_t x) {
    std::vector<std::pair<int64_t, int>> res;
    int ans = 0;
    for (int64_t i = 2; i < sqrt(x) + 1; ++i) {
        ans = 0;
        while (x % i == 0) {
            ++ans;
            x /= i;
        }
        if (ans != 0) {
            res.emplace_back(i, ans);
        }
    }
    if (x != 1) {
        res.emplace_back(x, 1);
    }
    return res;
}
