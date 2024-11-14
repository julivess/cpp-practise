#pragma once

#include <cstddef>
#include <vector>

class RingBuffer {
public:
    explicit RingBuffer(size_t capacity)
        : buffer_(capacity), max_size_(capacity), head_(0), tail_(0), count_(0) {
    }

    size_t Size() const {
        return count_;
    }

    bool Empty() const {
        return count_ == 0;
    }

    bool TryPush(int element) {
        if (count_ == max_size_) {
            return false;
        }
        buffer_[tail_] = element;
        tail_ = (tail_ + 1) % max_size_;
        ++count_;
        return true;
    }

    bool TryPop(int* element) {
        if (count_ == 0) {
            return false;
        }
        *element = buffer_[head_];
        head_ = (head_ + 1) % max_size_;
        --count_;
        return true;
    }

private:
    std::vector<int> buffer_;
    size_t max_size_;
    size_t head_;
    size_t tail_;
    size_t count_;
};
