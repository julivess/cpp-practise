#pragma once

#include <vector>
#include <stdexcept>

std::vector<int> Unique(const std::vector<int>& data) {
    std::vector<int> res;
    if (data.empty()) {
        return res;
    }
    res.push_back(data[0]);
    int n = data.size();
    for (int i = 0; i < n; ++i) {
        if (i != 0 && data[i] != data[i - 1]) {
            res.push_back(data[i]);
        }
    }
    return res;
}
