#pragma once

#include <array>
#include <cstddef>
#include <math.h>

class Vector {
public:
    Vector() : data_({0.0, 0.0, 0.0}) {
    }
    Vector(double x, double y, double z) : data_({x, y, z}) {
    }
    double& operator[](size_t ind) {
        return data_[ind];
    }
    double operator[](size_t ind) const {
        return data_[ind];
    }
    const Vector operator-(const Vector& vec) const {
        return Vector(data_[0] - vec[0], data_[1] - vec[1], data_[2] - vec[2]);
    }
    const Vector operator+(const Vector& vec) const {
        return Vector(data_[0] + vec[0], data_[1] + vec[1], data_[2] + vec[2]);
    }
    const Vector operator+(double alpha) const {
        return Vector(data_[0] + alpha, data_[1] + alpha, data_[2] + alpha);
    }
    const Vector operator*(const double& alph) const {
        return Vector(data_[0] * alph, data_[1] * alph, data_[2] * alph);
    }
    const Vector operator/(const double& alph) const {
        return Vector(data_[0] / alph, data_[1] / alph, data_[2] / alph);
    }
    void Normalize() {
        double length = std::sqrt(data_[0] * data_[0] + data_[1] * data_[1] + data_[2] * data_[2]);
        if (length != 0) {
            data_[0] = data_[0] / length;
            data_[1] = data_[1] / length;
            data_[2] = data_[2] / length;
        }
    }

private:
    std::array<double, 3> data_;
};

double DotProduct(const Vector& a, const Vector& b) {
    return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
}
Vector CrossProduct(const Vector& a, const Vector& b) {
    return {a[1] * b[2] - a[2] * b[1], a[2] * b[0] - a[0] * b[2], a[0] * b[1] - a[1] * b[0]};
}
double Length(const Vector& v) {
    return std::sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
}
