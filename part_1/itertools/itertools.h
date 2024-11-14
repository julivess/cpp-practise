#pragma once

#include <cstddef>
#include <stdexcept>

template <class Iterator>
class Sequence {
public:
    Sequence(Iterator begin, Iterator end) : begin_{begin}, end_{end} {
    }

    Iterator begin() const {
        return begin_;
    }

    Iterator end() const {
        return end_;
    }

private:
    Iterator begin_, end_;
};

template <class Iterator>
class RepeatIterator {
public:
    RepeatIterator(Iterator begin, Iterator end, size_t count = 0)
        : begin_{begin}, it_{begin}, end_{end}, count_{count} {
    }

    RepeatIterator& operator++() {
        if (!(++it_ != end_)) {
            ++count_;
            it_ = begin_;
        }
        return *this;
    }

    auto operator*() const {
        return *it_;
    }

    bool operator==(const RepeatIterator& rhs) const = default;

private:
    Iterator begin_, it_, end_;
    size_t count_;
};

auto Repeat(const auto& sequence, size_t n) {
    auto begin = sequence.begin();
    auto end = sequence.end();
    if (n && (begin != end)) {
        return Sequence{RepeatIterator{begin, end}, RepeatIterator{begin, end, n}};
    } else {
        return Sequence{RepeatIterator{end, end}, RepeatIterator{end, end}};
    }
}

template <class T>
class RangeIterator {
public:
    RangeIterator(T current, T step) : current_{current}, step_{step} {
    }
    auto& operator++() {
        current_ += step_;
        return *this;
    }
    auto operator*() const {
        return current_;
    }
    bool operator==(const RangeIterator& rhs) const = default;
    bool operator!=(const RangeIterator& rhs) const = default;

private:
    T current_, step_;
};

template <class T>
auto Range(T to) {
    T from = 0;
    T step = 1;
    return Sequence{
        RangeIterator{from, step},
        RangeIterator{from + ((to - from) / step + ((to - from) % step != 0 ? 1 : 0)) * step,
                      step}};
}

template <class T>
auto Range(T from, T to, T step = 1) {
    return Sequence{
        RangeIterator{from, step},
        RangeIterator{from + ((to - from) / step + ((to - from) % step != 0 ? 1 : 0)) * step,
                      step}};
}

template <class Iterator1, class Iterator2>
class ZipIterator {
public:
    ZipIterator(Iterator1 begin1, Iterator2 begin2) : it1_{begin1}, it2_{begin2} {
    }
    ZipIterator& operator++() {
        ++it1_;
        ++it2_;
        return *this;
    }
    bool operator==(const ZipIterator& rhs) const {
        return it1_ == rhs.it1_ || it2_ == rhs.it2_;
    }
    bool operator!=(const ZipIterator& rhs) const {
        return !(*this == rhs);
    }
    auto operator*() {
        return std::pair{*it1_, *it2_};
    }

private:
    Iterator1 it1_;
    Iterator2 it2_;
};

auto Zip(const auto& lhs, const auto& rhs) {
    auto it1 = ZipIterator{lhs.begin(), rhs.begin()};
    auto it2 = ZipIterator{lhs.end(), rhs.end()};
    return Sequence{it1, it2};
}

template <class Iterator>
class GroupIterator {
public:
    GroupIterator(Iterator begin, Iterator end)
        : end_{end}, cur_begin_{begin}, cur_end_{begin} {
        while (cur_end_ != end_ && *cur_end_ == *cur_begin_) {
            ++cur_end_;
        }
    }

    auto& operator++() {
        cur_begin_ = cur_end_;
        while (cur_end_ != end_ && *cur_begin_ == *cur_end_) {
            ++cur_end_;
        }
        return *this;
    }

    auto operator*() const {
        return Sequence{cur_begin_, cur_end_};
    }

    bool operator==(const GroupIterator& rhs) const {
        return cur_begin_ == rhs.cur_begin_ && cur_end_ == rhs.cur_end_;
    }
    bool operator!=(const GroupIterator& rhs) const {
        return !(*this == rhs);
    }

private:
    Iterator end_;
    Iterator cur_begin_, cur_end_;
};

template <class T>
auto Group(const T& sequence) {
    return Sequence{GroupIterator{sequence.begin(), sequence.end()},
                    GroupIterator{sequence.end(), sequence.end()}};
}