#pragma once

#include <string>
#include <cstddef>
#include <vector>

struct State {
    int ref_count;
    std::vector<std::string> data;
};

class COWVector {
public:
    COWVector() : state_(new State{}) {
        state_->ref_count = 1;
    }

    ~COWVector() {
        state_->ref_count--;
        if (state_->ref_count == 0) {
            delete state_;
        }
    }

    COWVector(const COWVector& other) : state_(other.state_) {
        state_->ref_count++;
    }

    COWVector& operator=(const COWVector& other) {
        if (this != &other) {
            state_->ref_count--;
            if (state_->ref_count == 0) {
                delete state_;
            }
            state_ = other.state_;
            state_->ref_count++;
        }
        return *this;
    }

    size_t Size() const {
        return state_->data.size();
    }

    void Resize(size_t size) {
        if (state_->data.size() == size) {
            return;
        }
        if (state_->ref_count > 1) {
            State* new_state = new State{};
            new_state->ref_count = 1;
            new_state->data = state_->data;
            state_->ref_count--;
            state_ = new_state;
        }
        state_->data.resize(size);
    }

    const std::string& Get(size_t at) const {
        return state_->data[at];
    }
    const std::string& Back() const {
        return state_->data.back();
    }

    void PushBack(const std::string& value) {
        if (state_->ref_count > 1) {
            State* new_state = new State{};
            new_state->ref_count = 1;
            new_state->data = state_->data;
            state_->ref_count--;
            state_ = new_state;
        }
        state_->data.push_back(value);
    }

    void Set(size_t at, const std::string& value) {
        if (state_->ref_count > 1) {
            State* new_state = new State{};
            new_state->ref_count = 1;
            new_state->data = state_->data;
            state_->ref_count--;
            state_ = new_state;
        }
        state_->data[at] = value;
    }

private:
    State* state_;
};
