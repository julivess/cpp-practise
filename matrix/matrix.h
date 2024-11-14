#pragma once

#include <vector>

class Matrix {
public:
    Matrix(std::size_t rows_size, std::size_t colums_size)
        : matrix_(rows_size, std::vector<double>(colums_size, 0)) {
    }

    Matrix(std::size_t dim) : matrix_(dim, std::vector<double>(dim, 0)) {
    }

    Matrix(std::vector<std::vector<double>> matrix) : matrix_(matrix) {
    }

    std::size_t Rows() const {
        return matrix_.size();
    }

    std::size_t Columns() const {
        return (Rows() > 0) ? matrix_[0].size() : 0;
    }

    double& operator()(std::size_t row, std::size_t col) {
        return matrix_[row][col];
    }

    const double& operator()(std::size_t row, std::size_t col) const {
        return matrix_[row][col];
    }

    Matrix operator+=(const Matrix& a) {
        for (std::size_t i = 0; i < this->Rows(); ++i) {
            for (std::size_t j = 0; j < Columns(); ++j) {
                this->matrix_[i][j] += a(i, j);
            }
        }
        return *this;
    }

    Matrix operator-=(const Matrix& a) {
        for (std::size_t i = 0; i < Rows(); ++i) {
            for (std::size_t j = 0; j < Columns(); ++j) {
                matrix_[i][j] -= a(i, j);
            }
        }
        return *this;
    }

    Matrix operator+(const Matrix& a) const {
        Matrix res(Rows(), Columns());
        res = *this;
        res += a;
        return res;
    }

    Matrix operator-(const Matrix& a) const {
        Matrix res(Rows(), Columns());
        res = *this;
        res -= a;
        return res;
    }

    Matrix operator*(const Matrix& a) const {
        Matrix res(Rows(), a.Columns());
        for (std::size_t i = 0; i < Rows(); ++i) {
            for (std::size_t j = 0; j < a.Columns(); ++j) {
                for (std::size_t k = 0; k < a.Rows(); ++k) {
                    res(i, j) += matrix_[i][k] * a(k, j);
                }
            }
        }
        return res;
    }

    Matrix operator*=(Matrix a) {
        *this = *this * a;
        return *this;
    }

private:
    std::vector<std::vector<double>> matrix_;
};

Matrix Transpose(Matrix othen) {
    Matrix res(othen.Columns(), othen.Rows());
    for (std::size_t i = 0; i < othen.Columns(); ++i) {
        for (std::size_t j = 0; j < othen.Rows(); ++j) {
            res(i, j) = othen(j, i);
        }
    }
    return res;
}

Matrix Identity(std::size_t n) {
    Matrix res(n);
    for (std::size_t i = 0; i < res.Rows(); ++i) {
        for (std::size_t j = 0; j < res.Columns(); ++j) {
            if (i == j) {
                res(i, j) = 1;
            }
        }
    }
    return res;
}
