#pragma once

#include <memory>
#include <vector>
#include <string>
#include <unordered_map>

template <class T>
std::vector<std::unique_ptr<T>> Duplicate(const std::vector<std::shared_ptr<T>>& items) {
    std::vector<std::unique_ptr<T>> res;
    for (auto it : items) {
        res.emplace_back(std::make_unique<T>(*it));
    }
    return res;
}

template <class T>
std::vector<std::shared_ptr<T>> DeDuplicate(const std::vector<std::unique_ptr<T>>& items) {
    std::unordered_map<T, std::shared_ptr<T>> map_it;
    std::vector<std::shared_ptr<T>> res;
    for (auto& it : items) {
        if (!map_it.contains(*it)) {
            map_it[*it] = std::make_shared<T>(*it);
        }
        res.push_back(map_it[*it]);
    }
    return res;
}
