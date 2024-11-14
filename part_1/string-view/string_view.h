#pragma once

#include <string>
#include <cstddef>
#include <cstring>

class StringView {
public:
    StringView(const std::string& str, size_t start = 0, size_t len_str = std::string::npos) {
        size_t actual_length = (len_str == std::string::npos) ? str.size() - start : len_str;
        if (start + actual_length > str.size()) {
            actual_length = str.size();
        }
        str_view_ = str.data() + start;
        len_str_ = actual_length;
    }
    StringView(const char* cstr) : str_view_(cstr), len_str_(std::strlen(cstr)) {
    }

    StringView(const char* cstr, size_t len_str) : str_view_(cstr), len_str_(len_str) {
    }
    const char& operator[](size_t i) const {
        return str_view_[i];
    }
    const char* Data() const {
        return str_view_;
    }
    size_t Size() const {
        return len_str_;
    }

private:
    const char* str_view_ = nullptr;
    size_t len_str_ = 0;
};
