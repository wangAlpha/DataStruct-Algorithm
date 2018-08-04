//
// Created by me on 01/08/2018.
//

#ifndef BITMAP_BITMAP_H
#define BITMAP_BITMAP_H

#include <cstdio>
#include <iostream>

class Bitmap {
  private:
    size_t *_data;
    size_t _size;
    void resize(size_t n) {
        if (_data != nullptr) {
            delete[] _data;
        }
        _size = n;
        _data = new size_t[n];
        memset(_data, 0, sizeof(size_t) * n);
    }
    void expand() {
        auto old_data = _data;
        auto old_size = _size;
        _size <<= 1;
        resize(_size);
        for (int i = 0; i < old_size; ++i) {
            _data[i] = old_data[i];
        }
        delete[] old_data;
    }

  public:
    Bitmap(size_t n = 5) {
        _data = nullptr;
        resize((n >> 5) + 1);
    }
    ~Bitmap() { delete[] _data; }
    void set(size_t n) {
        auto pos = n % 32;
        auto index = n >> 32;
        if (_size <= index) {
            expand();
        }
        _data[n >> 5] |= 1 << pos;
    }
    bool get(size_t n) {
        auto pos = n % 32;
        return _data[n >> 5] & (1 << pos);
    }
    void remove(size_t n) {
        auto pos = n % 32;
        _data[n >> 5] &= ~(1 << pos);
    }
    bool test(size_t n) { return get(n); }
};

#endif // BITMAP_BITMAP_H
