#pragma once

#include <vector>
#include <stdexcept>

std::vector<int> Range(int from, int to, int step = 1) {
    std::vector<int> res;
    if (from <= to && step <= 0) {
        return res;
    }
    if (from >= to && step >= 0) {
        return res;
    }
    if ((to - from) % step == 0) {
        int col = (to - from) / step;
        for (int i = 0; i < col; ++i) {
            res.push_back(from + i * step);
        }
        return res;
    }
    int col = (to - from) / step;
    for (int i = 0; i < col + 1; ++i) {
        res.push_back(from + i * step);
    }
    return res;
}
