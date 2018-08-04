#include <algorithm>
#include <iostream>
#include <vector>

const int32_t MOD = 100003;
const int CAPACITY = 1;

template <typename T> class Vector {
    T *_elem;
    int _size;
    int _capacity;

public:
    Vector() {
        _capacity = CAPACITY;
        _elem = new T[_capacity];
    }
    int find(T const &e) {
        for (int i = 0; i < _size; ++i) {
            if (_elem[i] == e) {
                return i;
            }
        }
        return -1;
    }
    void push_back(T const &e) {
        _elem[_size++] = e;
        if (_size >= _capacity) {
            auto old_elem = _elem;
            _elem = new T[(_capacity <<= 1)];
            for (int i = 0; i < _size; ++i) {
                *(_elem + i) = *(old_elem + i);
            }
            delete[] old_elem;
        }
    }
    T pop_back() { return _elem[--_size]; }
    T &index(int i) { return _elem[i]; }
    int size() const { return _size; }
};

template <typename T> class Hash {
private:
    Vector<T> _bucket[MOD];

public:
    bool put(T const &n) {
        auto r = n % MOD;
        if (_bucket[r].size() == 0) {
            _bucket[r].push_back(n);
            return true;
        } else {
            auto result = _bucket[r].find(n);
            if (result == -1) {
                _bucket[r].push_back(n);
                return true;
            } else {
                return false;
            }
        }
    }

    bool remove(T n) {
        auto r = n % MOD;
        if (_bucket[r].size() == 0) {
            return false;
        } else {
            auto result = _bucket[r].find(n);
            // std::find(std::begin(_bucket[r]), std::end(_bucket[r]), n);
            if (result == -1) {
                return false;
            } else {
                // *result = *(_bucket[r].end() - 1);
                _bucket[r].index(result) = _bucket[r].pop_back();
                _bucket[r].pop_back();
                return true;
            }
        }
    }
};

int main() {
    int n;
    std::cin >> n;
    Hash<int64_t> hash;
    for (int i = 0; i < n; ++i) {
        int op;
        int64_t number;
        std::cin >> op >> number;
        auto result = (op == 1) ? hash.put(number) : hash.remove(number);
        printf("%s\n", result ? "Succeeded" : "Failed");
    }
}