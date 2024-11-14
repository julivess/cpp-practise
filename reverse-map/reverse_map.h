#pragma once

#include <string>
#include <unordered_map>
#include <stdexcept>

std::unordered_map<int, std::string> ReverseMap(const std::unordered_map<std::string, int>& map) {
    std::unordered_map<int, std::string> res;
    for (const auto& element : map) {
        res[element.second] = element.first;
    }
    return res;
}
