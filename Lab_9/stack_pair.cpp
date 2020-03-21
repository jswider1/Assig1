#include "stack_pair.h"
#include <cassert>

template <class T>
stack_pair<T>::stack_pair() {
    this->top_a = 0;
    this->top_b = CAPACITY-1;
}

template <class T>
void stack_pair<T>::push_a(T item) {
    assert(!is_full_a());
    data[top_a++] = item;
}

template <class T>
void stack_pair<T>::push_b(T item) {
    assert(!is_full_b());
    data[top_b--] = item;
}


template <class T>
T stack_pair<T>::pop_a() {
    assert (!is_empty_a());
    return data[--top_a];
}


template <class T>
T stack_pair<T>::pop_b() {
    assert (!is_empty_b());
    return data[++top_b];
}

template <class T>
std::size_t stack_pair<T>::size_a() {
    return top_a;
}

template <class T>
std::size_t stack_pair<T>::size_b() {
    return CAPACITY - top_b - 1;
}

template <class T>
bool stack_pair<T>::is_empty_a() const {
    return top_a == 0;
}

template <class T>
bool stack_pair<T>::is_empty_b() const {
    return top_b == CAPACITY - 1;
}

template <class T>
bool stack_pair<T>::is_full_a() const {
    return top_a > top_b;
}

template <class T>
bool stack_pair<T>::is_full_b() const {
    return top_a > top_b;
}
