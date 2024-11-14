#pragma once

#include <vector>
#include <stdexcept>
#include <iostream>

std::vector<std::vector<int>> GeneratePermutations(size_t len) {
    std::vector<std::vector<int>> res;
    std::vector<int> perm(len);
    for (size_t i = 0; i < len; ++i) {
        perm[i] = i;
    }
    res.push_back(perm);
    while (true) {
        int k = -1;
        int l = -1;
        for (size_t i = 0; i < len - 1; ++i) {
            if (perm[i] < perm[i + 1]) {
                k = i;
            }
        }
        if (k == -1) {
            break;
        }
        for (size_t i = 0; i < len; ++i) {
            if (perm[i] > perm[k]) {
                l = i;
            }
        }
        std::swap(perm[k], perm[l]);
        int i = k + 1;
        int j = len - 1;
        while (i < j) {
            std::swap(perm[i], perm[j]);
            ++i;
            --j;
        }
        res.push_back(perm);
    }
    return res;
}
