#pragma once

#include <string>
#include <stdexcept>
#include <unordered_set>
#include <sstream>
#include <cctype>
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

int DifferentWordsCount(const std::string& string) {
    std::unordered_set<std::string> words;
    std::vector<std::string> str = Split(string);
    for (auto s : str) {
        std::string word;
        for (auto w : s) {
            if (std::isalpha(w)) {
                word += std::tolower(w);
            } else if (w == ',') {
                if (!word.empty()) {
                    words.insert(word);
                    word.clear();
                }
            }
        }
        if (!word.empty()) {
            words.insert(word);
        }
    }

    return words.size();
}
