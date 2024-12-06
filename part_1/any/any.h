#pragma once

#include <type_traits>
#include <typeinfo>
#include <concepts>
#include <utility>
#include <iostream>

template <class T>
concept NotAny = !std::same_as<std::remove_cvref_t<T>, class Any>;

struct HolderBase {
    virtual ~HolderBase() = default;
    virtual HolderBase* Clone() const = 0;
};

template <class T>
struct Holder : HolderBase {
    Holder(T&& val) : value{std::move(val)} {
    }

    Holder(const T& val) : value{val} {
    }

    HolderBase* Clone() const override {
        return new Holder<T>{value};
    }

    const T& GetHolder() {
        return value;
    }

    T value;
};

class Any {
public:
    Any() {
    }
    template <NotAny T>
    Any(T&& value) {
        using Nrt = typename std::remove_reference<T>::type;
        using Nct = typename std::remove_const<Nrt>::type;
        value_ = new Holder<Nct>(std::forward<T>(value));
    }

    Any(const Any& other) {
        value_ = (other.value_) ? other.value_->Clone() : nullptr;
    }
    Any(Any&& other) {
        value_ = other.value_;
        other.value_ = nullptr;
    }

    Any& operator=(const Any& other) {
        if (value_ == other.value_) {
            return *this;
        }
        HolderBase* tmp = nullptr;
        if (other.value_ != nullptr) {
            tmp = other.value_->Clone();
        }
        if (value_ != nullptr) {
            delete value_;
            value_ = nullptr;
        }
        value_ = tmp;
        return *this;
    }

    Any& operator=(Any&& other) {
        if (this == &other) {
            return *this;
        }
        if (value_ != nullptr) {
            delete value_;
            value_ = nullptr;
        }
        std::swap(value_, other.value_);
        return *this;
    }
    ~Any() {
        Clear();
    }

    bool Empty() const {
        return value_ == nullptr;
    }

    void Clear() {
        if (value_ != nullptr) {
            delete value_;
            value_ = nullptr;
        }
    }
    void Swap(Any& other) {
        HolderBase* tmp = value_;
        value_ = other.value_;
        other.value_ = tmp;
    }

    template <class T>
    const T& GetValue() const {
        using Nrt = typename std::remove_reference<T>::type;
        using Nct = typename std::remove_const<Nrt>::type;
        auto ptr = dynamic_cast<Holder<Nct>*>(value_);
        if (!ptr) {
            throw std::bad_cast();
        }
        return ptr->value;
    }

private:
    HolderBase* value_ = nullptr;
};