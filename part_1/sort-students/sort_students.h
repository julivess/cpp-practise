#pragma once

#include "student.h"

#include <vector>
#include <stdexcept>
#include <cctype>
#include <iostream>
#include <algorithm>
#include <cctype>

enum class SortType { kByName, kByDate };

struct StudentDate {
    bool operator()(const Student& a, const Student& b) const {
        if (a.year < b.year) {
            return true;
        } else if (a.year == b.year) {
            if (a.month < b.month) {
                return true;
            } else if (a.month == b.month) {
                if (a.day < b.day) {
                    return true;
                } else if (a.day == b.day) {
                    if (a.surname < b.surname) {
                        return true;
                    } else if (a.surname == b.surname) {
                        if (a.name < b.name) {
                            return true;
                        } else {
                            return true;
                        }
                    } else {
                        return false;
                    }
                } else {
                    return false;
                }
            } else {
                return false;
            }
        } else {
            return false;
        }
    }
};

struct StudentName {
    bool operator()(const Student& a, const Student& b) const {
        if (a.surname < b.surname) {
            return true;
        } else if (a.surname == b.surname) {
            if (a.name < b.name) {
                return true;
            } else if (a.name == b.name) {
                if (a.year < b.year) {
                    return true;
                } else if (a.year == b.year) {
                    if (a.month < b.month) {
                        return true;
                    } else if (a.month == b.month) {
                        if (a.day < b.day) {
                            return true;
                        } else {
                            return true;
                        }
                    } else {
                        return false;
                    }
                } else {
                    return false;
                }
            } else {
                return false;
            }
        } else {
            return false;
        }
    }
};

void SortStudents(std::vector<Student>* students, SortType sort_type) {
    for (auto st : *students) {
        std::transform(st.name.begin(), st.name.end(), st.name.begin(),
                       [](unsigned char c) { return std::tolower(c); });
        std::transform(st.surname.begin(), st.surname.end(), st.surname.begin(),
                       [](unsigned char c) { return std::tolower(c); });
    }
    if (sort_type == SortType::kByDate) {
        std::ranges::sort(*students, StudentDate{});
    } else if (sort_type == SortType::kByName) {
        std::ranges::sort(*students, StudentName{});
    }
}