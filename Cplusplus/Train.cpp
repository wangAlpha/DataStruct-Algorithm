#include <cstdio>
#include <iostream>

// 列车调度问题
// https://dsa.cs.tsinghua.edu.cn/oj/problem.shtml?id=1145

const auto STACK_SIZE = 1024;
template <typename T> class Stack {
    T *_elem;
    size_t _size, _capacity;
    // 扩容
    void expand() {
        _capacity <<= 1;
        auto old_elem = _elem;
        _elem = new T[_capacity];
        for (size_t i = 0; i < _size; ++i) {
            _elem[i] = old_elem[i];
        }
        delete[] old_elem;
    }
    // 缩容
    void shrink() {
        _capacity >>= 1;
        auto old_elem = _elem;
        _elem = new T[_capacity];
        for (size_t i = 0; i < _size; ++i) {
            _elem[i] = old_elem[i];
        }
        delete[] old_elem;
    }

public:
    Stack() {
        _capacity = STACK_SIZE;
        _elem = new T[_capacity];
        _size = 0;
    }
    ~Stack() { delete[] _elem; }

    size_t size() const { return _size; }
    void push(T const &e) {
        _elem[_size++] = e;
        if (_size >= _capacity - 1) {
            expand();
        }
    }
    T pop() { return _elem[--_size]; }
    T top() const { return _elem[_size - 1]; }
    bool empty() const { return size() == 0; }
    template <typename Fn> void visit(Fn fun) {
        for (int i = 0; i < _size; ++i) {
            fun(_elem[i]);
        }
    }
    T &index(size_t const n) { return _elem[n]; }
};

int main(int argc, char const *argv[]) {
    Stack<int> s;
    Stack<bool> record;
    int n, m;
    std::cin >> n >> m;
    int *train = new int[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> train[i];
    }
    int seq = 0;
    for (int i = 1; i <= n; ++i) {
        s.push(i);
        record.push(true);
        while (s.top() == train[seq] && seq < n) {
            s.pop();
            record.push(false);
            ++seq;
        }
        if (s.size() > m) {
            break;
        }
    }
    if (s.empty()) {
        for (int i = 0; i < record.size(); ++i) {
            printf("%s\n", record.index(i) ? "push" : "pop");
        }
    } else {
        printf("No\n");
    }
    return 0;
}
