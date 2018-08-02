#include "for_each.h"
#include <cstdio>
#include <gmpxx.h>
#include <iostream>
#include <queue>

const int HEAP_SIZE = 32;

template <class T> class Heap {
  private:
    T *_elem;
    int _size, _capacity;
    void heap(T *arr, int lo, int hi);
    void percolateUp(int lo, int hi);

    void percolateDown(int lo, int hi);
    void expand();
    bool InHeap(int x) { return (-1 < x && x < _size); }
    int LeftChild(int x) { return (x << 1) + 1; }
    int RightChild(int x) { return (x << 1) + 2; }
    int Parent(int x) { return ((x - 1) >> 1); }
    int ProperParent(int x);

  public:
    Heap();
    Heap(T *arr, int hi) {}
    ~Heap() { delete[] _elem; }

    T getMax() { return _elem[0]; }
    T delMax();
    void insert(T const &e);
    size_t size() const { return _size; }
    void headSort(T) {}
    template <typename Fn> void visit(Fn fun);
};

template <class T> template <typename Fn> void Heap<T>::visit(Fn fun) {
    for_each(_elem, _elem + _size, fun);
}

template <class T> Heap<T>::Heap() {
    _capacity = HEAP_SIZE;
    _size = 0;
    _elem = new T[_capacity];
}

template <class T> int Heap<T>::ProperParent(int x) {
    auto lc = LeftChild(x);
    auto rc = RightChild(x);
    if (!InHeap(lc)) {
        lc = x;
    }
    if (!InHeap(rc)) {
        rc = x;
    }
    if ((_elem[lc] > _elem[rc]) && (_elem[lc] > _elem[x])) {
        return lc;
    } else if ((_elem[rc] > _elem[lc]) && (_elem[rc] > _elem[x])) {
        return rc;
    } else {
        return x;
    }
}

template <class T> void Heap<T>::percolateDown(int lo, int hi) {
    int j;
    auto cur_pos = lo;
    while (cur_pos != (j = ProperParent(cur_pos))) {
        swap(_elem[cur_pos], _elem[j]);
        cur_pos = j;
    }
}

template <class T> void Heap<T>::percolateUp(int lo, int hi) {
    auto cur_pos = hi - 1;
    while (InHeap(cur_pos)) {
        auto parent = Parent(cur_pos);
        if (InHeap(parent)) {
            if (_elem[parent] < _elem[cur_pos]) {
                swap(_elem[parent], _elem[cur_pos]);
            }
        }
        cur_pos = parent;
    }
}

template <class T> void Heap<T>::expand() {
    auto old_elem = _elem;
    _capacity <<= 1;
    _elem = new T[_capacity];
    copy(_elem, old_elem, old_elem + _size);
    delete[] old_elem;
}

template <class T> void Heap<T>::insert(const T &e) {
    _elem[_size++] = e;
    percolateUp(0, _size);
    if (_size >= _capacity) {
        expand();
    }
}

template <class T> T Heap<T>::delMax() {
    auto max_elem = _elem[0];
    _elem[0] = _elem[--_size];
    percolateDown(0, _size);
    return max_elem;
}

int main(int argc, char const *argv[]) {
    Heap<int> heap;
    int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    for_each(array, array + 13, [](int *e) { std::cout << *e << ' '; });
    std::cout << '\n';
    for_each(array, array + 13, [&](int *e) { heap.insert(*e); });
    std::cout << '\n';
    for (int i = 0; i < 13; ++i) {
        std::cout << heap.getMax() << ' ';
        heap.delMax();
    }
    std::cout << '\n';
    return 0;
}
