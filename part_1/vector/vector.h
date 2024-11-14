#pragma once

#include <initializer_list>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <cstddef>

class Vector {
public:
    Vector() : vector_(nullptr), size_(0), capacity_(0) {
    }
    Vector(const size_t size) : vector_(new int[size]()), size_(size), capacity_(size) {
    }
    Vector(const std::initializer_list<int>& list)
        : vector_(new int[list.size()]), size_(list.size()), capacity_(list.size()) {
        std::copy(list.begin(), list.end(), vector_);
    }
    Vector(const Vector& copy)
        : vector_(new int[copy.capacity_]), size_(copy.size_), capacity_(copy.capacity_) {
        std::copy(copy.vector_, copy.vector_ + copy.size_, vector_);
    }
    Vector(Vector&& other) noexcept
        : vector_(other.vector_), size_(other.size_), capacity_(other.capacity_) {
        other.vector_ = nullptr;
        other.size_ = 0;
        other.capacity_ = 0;
    }
    Vector& operator=(const Vector& vec) {
        if (this != &vec) {
            delete[] vector_;
            size_ = vec.size_;
            capacity_ = vec.capacity_;
            vector_ = new int[capacity_];
            std::copy(vec.vector_, vec.vector_ + size_, vector_);
        }
        return *this;
    }
    Vector& operator=(Vector&& other) noexcept {
        if (this != &other) {
            delete[] vector_;
            vector_ = other.vector_;
            size_ = other.size_;
            capacity_ = other.capacity_;
            other.vector_ = nullptr;
            other.size_ = 0;
            other.capacity_ = 0;
        }
        return *this;
    }
    ~Vector() {
        delete[] vector_;
    }
    void Swap(Vector& vec) {
        std::swap(vector_, vec.vector_);
        std::swap(size_, vec.size_);
        std::swap(capacity_, vec.capacity_);
    }
    int& operator[](size_t ind) {
        return vector_[ind];
    }
    const int& operator[](size_t ind) const {
        return vector_[ind];
    }
    size_t Size() const {
        return size_;
    }
    size_t Capacity() const {
        return capacity_;
    }
    void PushBack(int elem) {
        if (size_ >= capacity_) {
            Reserve(capacity_ ? capacity_ * 2 : 1);
        }
        vector_[size_++] = elem;
    }
    void PopBack() {
        if (size_ > 0) {
            --size_;
        }
    }
    void Clear() {
        size_ = 0;
    }
    void Reserve(size_t new_cap) {
        if (new_cap > capacity_) {
            int* new_vec = new int[new_cap];
            std::copy(vector_, vector_ + size_, new_vec);
            delete[] vector_;
            vector_ = new_vec;
            capacity_ = new_cap;
        }
    }

    class Iterator {
    public:
        using iterator_category = std::random_access_iterator_tag;
        using value_type = int;
        using difference_type = ptrdiff_t;
        using pointer = int*;
        using reference = int&;

        Iterator(int* p) : iter_(p) {
        }

        Iterator() = default;

        int& operator*() const {
            return *iter_;
        }

        int* operator->() const {
            return iter_;
        }

        Iterator& operator++() {
            ++iter_;
            return *this;
        }
        Iterator operator++(int) {
            Iterator temp = *this;
            ++iter_;
            return temp;
        }
        Iterator& operator--() {
            --iter_;
            return *this;
        }
        Iterator operator--(int) {
            Iterator temp = *this;
            --iter_;
            return temp;
        }
        auto operator<=>(const Iterator& other) const = default;

        Iterator& operator+=(difference_type n) {
            iter_ += n;
            return *this;
        }
        Iterator operator+(difference_type n) const {
            return Iterator(iter_ + n);
        }
        friend Iterator operator+(difference_type n, const Iterator& it) {
            return Iterator{it.iter_ + n};
        }
        Iterator& operator-=(difference_type n) {
            iter_ -= n;
            return *this;
        }
        Iterator operator-(difference_type n) const {
            return Iterator(iter_ - n);
        }
        difference_type operator-(const Iterator& other) const {
            return iter_ - other.iter_;
        }
        reference operator[](difference_type ind) const {
            return iter_[ind];
        }

    private:
        int* iter_;
    };
    Iterator begin() {
        return Iterator(vector_);
    }
    Iterator end() {
        return Iterator(vector_ + size_);
    }

private:
    int* vector_;
    size_t size_;
    size_t capacity_;
};
