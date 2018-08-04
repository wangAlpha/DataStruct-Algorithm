// #include "for_each.h"
#include <cstdio>
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
    void heapify(int n);

    void expand();
    bool InHeap(int x) { return (-1 < x && x < _size); }
    int LeftChild(int x) { return (x << 1) + 1; }
    int RightChild(int x) { return (x << 1) + 2; }
    int Parent(int x) { return ((x - 1) >> 1); }
    int ProperParent(int x);
    bool InternalNode(int x) { return ((x >> 1) - 1) && InHeap(x); }

public:
    Heap();
    Heap(T *arr, int n);
    ~Heap() { delete[] _elem; }

    T getMax() { return _elem[0]; }
    T delMax();
    void insert(T const &e);
    size_t size() const { return _size; }
    void heapSort();
    template <typename Fn> void visit(Fn fun);
};
// 遍历堆
template <class T> template <typename Fn> void Heap<T>::visit(Fn fun) {
    for_each(_elem, _elem + _size, fun);
}
// 构造函数
template <class T> Heap<T>::Heap() {
    _capacity = HEAP_SIZE;
    _size = 0;
    _elem = new T[_capacity];
}
template <class T> Heap<T>::Heap(T *arr, int n) {
    _size = n;
    _elem = new T[_capacity];
    copy(_elem, arr, arr + n);
    heapify(n);
}
// 返回节点中的最大节点
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
// 下滤
template <class T> void Heap<T>::percolateDown(int lo, int hi) {
    int j;
    auto cur_pos = lo;
    while (cur_pos != (j = ProperParent(cur_pos))) {
        std::swap(_elem[cur_pos], _elem[j]);
        cur_pos = j;
    }
}
// 上滤
template <class T> void Heap<T>::percolateUp(int lo, int hi) {
    auto cur_pos = hi - 1;
    while (InHeap(cur_pos)) {
        auto parent = Parent(cur_pos);
        if (InHeap(parent)) {
            if (_elem[parent] < _elem[cur_pos]) {
                std::swap(_elem[parent], _elem[cur_pos]);
            }
        }
        cur_pos = parent;
    }
}
template <class T> void Heap<T>::heapify(int n) {
    for (int i = 1; i < _size && InternalNode(i); ++i) {
        percolateDown(i, _size);
    }
    for_each(_elem, _elem + _size, [&](int *e) { std::cout << *e << ' '; });
}
// 扩展
template <class T> void Heap<T>::expand() {
    auto old_elem = _elem;
    _capacity <<= 1;
    _elem = new T[_capacity];
    copy(_elem, old_elem, old_elem + _size);
    delete[] old_elem;
}
// 插入元素
template <class T> void Heap<T>::insert(const T &e) {
    _elem[_size++] = e;
    percolateUp(0, _size);
    if (_size >= _capacity) {
        expand();
    }
}
// 移除最大值
template <class T> T Heap<T>::delMax() {
    auto max_elem = _elem[0];
    _elem[0] = _elem[--_size];
    percolateDown(0, _size);
    return max_elem;
}
//  堆排序
template <class T> void Heap<T>::heapSort() {
    int index = _size - 1;
    while (index) {
        _elem[index--] = delMax();
    }
}

template <typename T> struct BinNode {
    BinNode *left;
    BinNode *right;
    T e;
    BinNode() {}
    BinNode(T const &data) : left(nullptr), right(nullptr), e(data) {}
    BinNode(BinNode *l, BinNode *r, T const &data)
        : left(l), right(r), e(data) {}

    bool operator>(BinNode const &node) { return e < node.e; }
    bool operator<(BinNode const &node) { return e > node.e; }
    bool operator==(BinNode const &node) { return e == node.e; }
    BinNode &operator=(BinNode const &node) {
        left = node.left;
        right = node.right;
        e = node.e;
        return *this;
    }
};

template <typename T> class BinTree {
private:
    BinNode<T> *_root;

public:
    void insert(T const &e) {}
    void visit() {}
};

int main(int argc, char const *argv[]) {
    // BinTree<int> tree;
    // Heap<BinNode<int> *> huffman;
    std::priority_queue<BinNode<int> *> huffman;
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        int e;
        std::cin >> e;
        huffman.push(new BinNode<int>(e));
        // huffman.insert(new BinNode<int>(e));
    }
    int weight = 0;
    while (huffman.size() != 1) {
        auto node = huffman.top();
        huffman.pop();
        auto new_node = huffman.top();
        huffman.pop();
        std::cout << node->e << ' ' << new_node->e << std::endl;
        new_node->e += node->e;
        // std::cout << new_node->e << ' ';
        weight += new_node->e;
        delete node;
        huffman.push(new_node);
    }
    printf("%d\n", weight);
    return 0;
}
