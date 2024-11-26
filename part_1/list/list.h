#pragma once

#include <cstddef>
#include <iterator>

struct Node {
    Node* next = this;
    Node* prev = this;
    virtual ~Node() = default;
};

template <class T>
struct ListNode : Node {
    T data;
    ListNode(const T& val) : data(val) {
        next = nullptr;
        prev = nullptr;
    }
    ListNode(T&& val) : data(std::move(val)) {
        next = nullptr;
        prev = nullptr;
    }
    ~ListNode() = default;
};

template <class T>
class List {
public:
    class Iterator {
    public:
        using iterator_category = std::bidirectional_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = T*;
        using reference = T&;

        Iterator(Node* other) : node_{other} {
        }
        Iterator() = default;
        Iterator& operator++() {
            node_ = node_->next;
            return *this;
        }
        Iterator operator++(int) {
            Iterator tmp = *this;
            node_ = node_->next;
            return tmp;
        }
        Iterator& operator--() {
            node_ = node_->prev;
            return *this;
        }
        Iterator operator--(int) {
            Iterator tmp = *this;
            node_ = node_->prev;
            return tmp;
        }
        T& operator*() const {
            return dynamic_cast<ListNode<T>*>(node_)->data;
        }
        T* operator->() const {
            return &dynamic_cast<ListNode<T>*>(node_)->data_;
        }
        bool operator==(const Iterator& other) const {
            return node_ == other.node_;
        }
        bool operator!=(const Iterator& other) const {
            return node_ != other.node_;
        }
        Node* GetIter() const {
            return node_;
        }

    private:
        Node* node_ = nullptr;
    };

    List() {
        head_ = new Node;
        size_ = 0;
    }

    bool IsEmpty() const {
        return !Size();
    }
    size_t Size() const {
        return size_;
    }

    void PushBack(const T& val) {
        auto new_node = new ListNode<T>(val);
        LinkAfter(head_->prev, new_node);
    }
    void PushBack(T&& val) {
        auto new_node = new ListNode<T>(std::move(val));
        LinkAfter(head_->prev, new_node);
    }
    void PushFront(const T& val) {
        auto new_node = new ListNode<T>(val);
        LinkAfter(head_, new_node);
    }
    void PushFront(T&& val) {
        auto new_node = new ListNode<T>(std::move(val));
        LinkAfter(head_, new_node);
    }

    T& Front() {
        auto ptr = head_->next;
        return dynamic_cast<ListNode<T>*>(ptr)->data;
    }
    const T& Front() const {
        auto ptr = head_->next;
        return dynamic_cast<ListNode<T>*>(ptr)->data;
    }
    T& Back() {
        auto ptr = head_->prev;
        return dynamic_cast<ListNode<T>*>(ptr)->data;
    }
    const T& Back() const {
        auto ptr = head_->prev;
        return dynamic_cast<ListNode<T>*>(ptr)->data;
    }

    void PopBack() {
        auto tmp = head_->prev;
        Unlink(tmp);
    }
    void PopFront() {
        auto tmp = head_->next;
        Unlink(tmp);
    }

    void Erase(Iterator itr) {
        Unlink(itr.GetIter());
    }

    Iterator Begin() {
        return Iterator(head_->next);
    }
    Iterator End() {
        return Iterator(head_);
    }
    List(const List& other) {
        size_ = 0;
        head_ = new Node;
        auto it = other.head_->next;
        for (; it != other.head_;) {
            T value = dynamic_cast<ListNode<T>*>(it)->data;
            PushBack(value);
            it = it->next;
        }
    }
    List(List&& other) : head_(other.head_), size_(other.size_) {
        other.head_ = new Node;
        other.size_ = 0;
    }
    ~List() {
        while (head_->next != head_) {
            PopBack();
        }
        head_->next = nullptr;
        head_->prev = nullptr;
        delete head_;
        size_ = 0;
    }
    List& operator=(const List& other) {
        if (&other == this) {
            return *this;
        }
        this->~List();
        size_ = 0;
        head_ = new Node;
        auto it = other.head_->next;
        for (; it != other.head_;) {
            T val = dynamic_cast<ListNode<T>*>(it)->data;
            PushBack(val);
            it = it->next;
        }
        return *this;
    }
    List& operator=(List&& other) {
        if (&other == this) {
            return *this;
        }
        this->~List();
        size_ = other.size_;
        head_ = other.head_;
        other.head_ = new Node;
        other.size_ = 0;
        return *this;
    }

private:
    Node* head_;
    size_t size_;
    void Unlink(Node* node) {
        if (head_ == node) {
            return;
        }
        auto node_next = node->next;
        auto node_prev = node->prev;
        node_next->prev = node_prev;
        node_prev->next = node_next;
        --size_;
        node->prev = nullptr;
        node->next = nullptr;
        delete node;
    }
    void LinkAfter(Node* target, Node* after) {
        auto old_next = target->next;
        target->next = after;
        after->prev = target;
        after->next = old_next;
        old_next->prev = after;
        ++size_;
    }
};

template <class T>
List<T>::Iterator begin(List<T>& list) {
    return list.Begin();
}

template <class T>
List<T>::Iterator end(List<T>& list) {
    return list.End();
}