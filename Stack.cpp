#include <cstdio>
#include <iostream>

#define INIT_CAPACITY 16
template <typename T> class Stack {
private:
public:
    T *_elem;
    size_t len, capacity;

    Stack() {
        len = 0;
        capacity = INIT_CAPACITY;
        _elem = new T[capacity];
    }
    void push(const T e) {
        _elem[len++] = e;
        if (len >= capacity - 1) {
            dealloc();
        }
    }

    T pop() {
        if (len == 0) {
            throw 0;
        }
        return _elem[--len];
    }
    void dealloc() {
        capacity <<= 1;
        auto old_elem = _elem;
        _elem = new T[capacity];
        for_each(_elem, _elem + len - 1, [&old_elem](int n) {

        });
        for (auto i = 0; i < len; ++i) {
            _elem[i] = old_elem[i];
        }
        delete old_elem;
    }
    bool empty() { return len == 0; }
};

template <typename T, typename Fn> void foreach (T count, Fn fn) {
    for (auto i = 0; i < count; ++i) {
        fn(i);
    }
}
int main(int argc, char const *argv[]) {
    int timer;
    std::cin >> timer;
    Stack<char *> s;
    for (int i = 0; i < timer; ++i) {
        int op = 0;
        scanf("%d", &op);
        if (op == 1) {
            auto str = new char[16];
            scanf("%s", str);
            s.push(str);
        } else if (op == 2) {
            printf("%s\n", s.pop());
        } else if (op == 3) {
            int pos;
            scanf("%d", &pos);
            printf("%s\n", s._elem[pos - 1]);
        }
    }
    return 0;
}
