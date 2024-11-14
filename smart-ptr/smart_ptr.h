#pragma once

#include <string>
#include <string>
#include <iostream>

class WeakPtr;

struct Counter {
    int strong = 0;
    int week = 0;
};

class SharedPtr {
    friend class WeakPtr;

public:
    SharedPtr() {
        string_ = nullptr;
        counter_ = nullptr;
    }

    SharedPtr(std::string* str) : string_(str), counter_(new Counter({1, 0})) {
    }

    SharedPtr(const WeakPtr& ptr);

    SharedPtr(const SharedPtr& other) {
        string_ = other.string_;
        counter_ = other.counter_;
        if (counter_) {
            ++(counter_->strong);
        }
    }

    SharedPtr(SharedPtr&& other) {
        std::swap(string_, other.string_);
        std::swap(counter_, other.counter_);
        other.string_ = nullptr;
        other.counter_ = nullptr;
    }

    ~SharedPtr() {
        if (!counter_) {
            return;
        }
        if (--(counter_->strong) == 0) {
            delete string_;
            if (counter_->week == 0) {
                delete counter_;
            }
        }
    }

    SharedPtr& operator=(const SharedPtr& other) {
        if (other.string_ == string_ && other.counter_ == counter_) {
            return *this;
        }
        SharedPtr copy(other);
        std::swap(string_, copy.string_);
        std::swap(counter_, copy.counter_);
        return *this;
    }

    SharedPtr& operator=(SharedPtr&& other) {
        if (other.string_ == string_ && other.counter_ == counter_) {
            return *this;
        }
        std::swap(other.counter_, counter_);
        std::swap(other.string_, string_);
        return *this;
    }

    std::string& operator*() const {
        return *string_;
    }

    std::string* operator->() const {
        return string_;
    }

    std::string* Get() const {
        return string_;
    }

    void Reset(std::string* ptr) {
        if (counter_ && counter_->strong == 1) {
            delete string_;
            string_ = ptr;
        } else {
            --(counter_->strong);
            string_ = ptr;
            counter_ = new Counter({1, 0});
        }
    }

private:
    std::string* string_ = nullptr;
    Counter* counter_ = nullptr;
};

class WeakPtr {
public:
    WeakPtr() = default;

    WeakPtr(const SharedPtr& ptr) : string_(ptr.string_), counter_(ptr.counter_) {
        if (counter_) {
            ++counter_->week;
        }
    }

    WeakPtr(const WeakPtr& other) : string_(other.string_), counter_(other.counter_) {
        if (counter_) {
            ++counter_->week;
        }
    }

    WeakPtr(WeakPtr&& other) : string_(other.string_), counter_(other.counter_) {
        other.string_ = nullptr;
        other.counter_ = nullptr;
    }

    SharedPtr Lock() {
        SharedPtr result;
        if (!IsExpired()) {
            result.counter_ = counter_;
            result.string_ = string_;
            ++counter_->strong;
        }
        return result;
    }

    WeakPtr& operator=(const WeakPtr& other) {
        WeakPtr new_ptr(other);
        std::swap(string_, new_ptr.string_);
        std::swap(counter_, new_ptr.counter_);
        return *this;
    }

    WeakPtr& operator=(WeakPtr&& other) {
        std::swap(other.counter_, counter_);
        std::swap(other.string_, string_);
        return *this;
    }

    ~WeakPtr() {
        if (counter_) {
            --counter_->week;
            if (counter_->week == 0 && counter_->strong == 0) {
                delete counter_;
            }
        }
    }

    std::string& operator*() const {
        return *string_;
    }

    std::string* operator->() const {
        return string_;
    }

    std::string* Get() const {
        return string_;
    }

    Counter* GetBlock() const {
        return counter_;
    }

    bool IsExpired() const {
        if (counter_) {
            return counter_->strong <= 0;
        }
        return true;
    }

private:
    std::string* string_ = nullptr;
    Counter* counter_ = nullptr;
};

SharedPtr::SharedPtr(const WeakPtr& ptr) : string_(ptr.Get()), counter_(ptr.GetBlock()) {
    if (ptr.IsExpired()) {
        string_ = nullptr;
    }
    if (counter_) {
        ++(counter_->strong);
    }
}