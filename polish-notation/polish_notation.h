#pragma once

#include <string>
#include <stdexcept>
#include <vector>
#include <stack>

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

int EvaluateExpression(const std::string& expression) {
    const std::vector<std::string>& exp = Split(expression);
    std::stack<int> stk;

    for (const auto& k : exp) {
        if (std::isdigit(k[0]) || (k.size() > 1 && k[0] == '-')) {
            stk.push(std::stoi(k));
        } else {
            int b = stk.top();
            stk.pop();
            int a = stk.top();
            stk.pop();
            if (k == "+") {
                stk.push(a + b);
            } else if (k == "-") {
                stk.push(a - b);
            } else if (k == "*") {
                stk.push(a * b);
            } else if (k == "/") {
                stk.push(a / b);
            }
        }
    }
    return stk.top();
}
