#pragma once

#include <vector>
#include <string>
#include <utility>
#include <algorithm>

class StaticMap {
public:
    explicit StaticMap(const std::vector<std::pair<std::string, std::string>>& items) {
        std::vector<std::pair<std::string, std::string>> map = items;
        std::ranges::sort(map);
        map_ = map;
    }

    bool Find(const std::string& key, std::string* value) const {
        std::pair<std::string, std::string> fict = {key, ""};
        auto it = std::lower_bound(map_.begin(), map_.end(), fict);
        if (it != map_.end() && it->first == key) {
            *value = it->second;
            return true;
        }
        return false;
    }

private:
    std::vector<std::pair<std::string, std::string>> map_;
};
