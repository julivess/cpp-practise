#pragma once

#include <string>
#include <stdexcept>
#include <algorithm>

std::string LongSum(const std::string& a, const std::string& b) {
    std::string result;
    int memor = 0;

    int len1 = a.size();
    int len2 = b.size();
    int i_ind = len1 - 1;
    int j_ind = len2 - 1;

    while (i_ind >= 0 || j_ind >= 0 || memor) {
        int digit1;
        int digit2;
        if (i_ind >= 0) {
            digit1 = a[i_ind] - '0';
        } else {
            digit1 = 0;
        }
        if (j_ind >= 0) {
            digit2 = b[j_ind] - '0';
        } else {
            digit2 = 0;
        }
        int sum = digit1 + digit2 + memor;
        memor = sum / 10;
        result.push_back((sum % 10) + '0');
        --i_ind;
        --j_ind;
    }
    std::reverse(result.begin(), result.end());
    return result;
}