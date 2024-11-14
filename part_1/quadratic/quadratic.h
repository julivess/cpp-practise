#pragma once

#include <stdexcept>
#include <math.h>

enum class RootCount { kZero, kOne, kTwo, kInf };

struct Roots {
    RootCount count;
    double first;
    double second;
    Roots() {
    }
};

Roots SolveQuadratic(int a, int b, int c) {
    Roots res;
    if (a == 0 && b == 0 && c == 0) {
        res.count = RootCount::kInf;
        return res;
    }
    if (a == 0 && b == 0) {
        res.count = RootCount::kZero;
        return res;
    } else if (a == 0 && b != 0) {
        res.count = RootCount::kOne;
        res.first = -static_cast<double>(c) / b;
        return res;
    }
    double discriminant = (b * b) - (4 * a * c);
    if (discriminant < 0) {
        res.count = RootCount::kZero;
    }
    if (discriminant == 0) {
        res.first = -static_cast<double>(b) / (2 * a);
        res.count = RootCount::kOne;
    }
    if (discriminant > 0) {
        res.count = RootCount::kTwo;
        double x1 = (-static_cast<double>(b) - std::sqrt(discriminant)) / (2 * a);
        double x2 = (-static_cast<double>(b) + std::sqrt(discriminant)) / (2 * a);
        if (x1 < x2) {
            res.first = x1;
            res.second = x2;
        } else {
            res.first = x2;
            res.second = x1;
        }
    }
    return res;
}
