#pragma once

#include <string>
#include <list>
#include <string>
#include <unordered_map>

class LruCache {
public:
    explicit LruCache(size_t max_size) : max_size_(max_size) {
    }
    LruCache(const LruCache&) = delete;
    LruCache& operator=(const LruCache&) = delete;

    void Set(const std::string& key, const std::string& value) {
        auto it = cache_.find(key);
        if (it != cache_.end()) {
            it->second->second = value;
            lru_list_.splice(lru_list_.begin(), lru_list_, it->second);
            return;
        }
        lru_list_.emplace_front(key, value);
        cache_[key] = lru_list_.begin();

        if (cache_.size() > max_size_) {
            auto last_it = lru_list_.end();
            --last_it;
            cache_.erase(last_it->first);
            lru_list_.pop_back();
        }
    }

    bool Get(const std::string& key, std::string* value) {
        auto it = cache_.find(key);
        if (it == cache_.end()) {
            return false;
        }
        *value = it->second->second;
        lru_list_.splice(lru_list_.begin(), lru_list_, it->second);
        return true;
    }

private:
    size_t max_size_;
    std::list<std::pair<std::string, std::string>> lru_list_;
    std::unordered_map<std::string, std::list<std::pair<std::string, std::string>>::iterator>
        cache_;
};
