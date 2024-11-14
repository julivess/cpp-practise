#pragma once

#include "vector.h"
#include <array>

#include <cstddef>

class Triangle {
public:
    Triangle(const Vector& a, const Vector& b, const Vector& c) : triangle_{a, b, c} {
    }
    Triangle() {
        Vector tmp{};
        triangle_ = {tmp, tmp, tmp};
    }
    const Vector& operator[](size_t ind) const {
        return triangle_[ind];
    }
    double Area() const {
        Vector first = triangle_[1] - triangle_[0];
        Vector second = triangle_[2] - triangle_[0];
        Vector cross = CrossProduct(first, second);
        return 0.5 * Length(cross);
    }

private:
    std::array<Vector, 3> triangle_;
};
