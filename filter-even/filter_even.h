#pragma once

#include <vector>
#include <stdexcept>

void FilterEven(std::vector<int>* data) {
    std::vector<int> res;
    for (auto i : *data) {
        if (i % 2 == 0) {
            res.push_back(i);
        }
    }
    *data = res;
}