#pragma once

#include <string>
#include <stdexcept>
#include <vector>

std::vector<std::string> Split(const std::string& string, const std::string& delimiter = " ") {
    std::vector<std::string> res;
    if (string.empty()) {
        return res;
    }
    size_t start = 0;
    size_t end = string.find(delimiter);
    while (end != std::string::npos) {
        res.push_back(string.substr(start, end - start));
        start = end + delimiter.length();
        end = string.find(delimiter, start);
    }
    res.push_back(string.substr(start, end));
    return res;
}
