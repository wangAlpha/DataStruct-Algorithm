#pragma once

template <typename T, typename Fn> void for_each(T begin, T end, Fn fun) {
    for (; begin != end; ++begin) {
        fun(begin);
    }
}

template <typename T> void copy(T *dst, T *begin, T *end) {
    for (; begin != end; ++begin) {
        *dst++ = *begin;
    }
}

template <typename T> void swap(T &a, T &b) {
    T e = a;
    a = b;
    b = e;
}
template <typename T> T max(T &a, T &b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}
