#pragma once

#include <algorithm>
#include <cstddef> // для size_t

template <typename T>
class SimpleVector {
public:
    SimpleVector() noexcept;
    explicit SimpleVector(size_t size);
    ~SimpleVector();

    T& operator[](size_t index);
    const T& operator[](size_t index) const;

    T* begin() noexcept;
    T* end() noexcept;
    const T* begin() const noexcept;
    const T* end() const noexcept;

    size_t Size() const noexcept;
    size_t Capacity() const noexcept;
    void PushBack(const T& value);

private:
    T* data_ = nullptr;
    size_t size_ = 0;
    size_t capacity_ = 0;

    void ExpandIfNeeded();
};

// Реалізація методів класу SimpleVector
template <typename T>
SimpleVector<T>::SimpleVector() noexcept = default;

template <typename T>
SimpleVector<T>::SimpleVector(size_t size)
    : data_(new T[size]{}), size_(size), capacity_(size) {}

template <typename T>
SimpleVector<T>::~SimpleVector() {
    delete[] data_;
}

template <typename T>
T& SimpleVector<T>::operator[](size_t index) {
    return data_[index];
}

template <typename T>
const T& SimpleVector<T>::operator[](size_t index) const {
    return data_[index];
}

template <typename T>
T* SimpleVector<T>::begin() noexcept {
    return data_;
}

template <typename T>
T* SimpleVector<T>::end() noexcept {
    return data_ + size_;
}

template <typename T>
const T* SimpleVector<T>::begin() const noexcept {
    return data_;
}

template <typename T>
const T* SimpleVector<T>::end() const noexcept {
    return data_ + size_;
}

template <typename T>
size_t SimpleVector<T>::Size() const noexcept {
    return size_;
}

template <typename T>
size_t SimpleVector<T>::Capacity() const noexcept {
    return capacity_;
}

template <typename T>
void SimpleVector<T>::PushBack(const T& value) {
    ExpandIfNeeded();
    data_[size_++] = value;
}

template <typename T>
void SimpleVector<T>::ExpandIfNeeded() {
    if (size_ == capacity_) {
        size_t new_capacity = capacity_ == 0 ? 1 : 2 * capacity_;
        T* new_data = new T[new_capacity];
        std::copy(data_, data_ + size_, new_data);
        delete[] data_;
        data_ = new_data;
        capacity_ = new_capacity;
    }
}
