#include <cstdio>
#include <iostream>
#include <vector>

const auto STACK_SIZE = 1024;
template <typename T> class Stack {
    T *_elem;
    size_t _size;

public:
    Stack() {
        _elem = new T[STACK_SIZE];
        _size = 0;
    }
    ~Stack() { delete[] _elem; }
    size_t size() const { return _size; }
    void push(T const &e) { _elem[_size++] = e; }
    T pop() { return _elem[--_size]; }
    bool empty() const { return size() == 0; }
    template <typename Fn> void visit(Fn fun) {
        for (int i = 0; i < _size; ++i) {
            fun(_elem[i]);
        }
    }
};

void sorting(Stack<int> &s) {
    Stack<int> ss;
    for (int i = 0; i < s.size(); ++i) {
        if
    }
}

int main() {
    Stack<int> s;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int number;
        scanf("%d", &number);
        s.push(number);
    }
    s.visit([](int e) { printf("%d ", e); });
    std::cout << '\n';

    s.visit([](int e) { printf("%d ", e); });
    std::cout << '\n';
    return 0;
}