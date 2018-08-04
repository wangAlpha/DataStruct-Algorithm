#include <iostream>

const int32_t MOD = 100003;
template <typename T> struct list_node {
    list_node *next;
    T data;
    list_node(T const &e) : next(nullptr), data(e) {}
};

template <typename T> class List {
private:
    list_node<T> *header;

public:
    List() { header = nullptr; }
    void insert(T const &e) {
        if (header == nullptr) {
            header = new list_node<T>(e);
        } else {
            auto l = header;
            while (l->next != nullptr) {
                l = l->next;
            }
            l->next = new list_node<T>(e);
        }
    }

    list_node<T> *find(T const &e) {
        if (header == nullptr) {
            return nullptr;
        }
        auto node = header;
        while (node != nullptr) {
            if (node->data == e) {
                break;
            }
            node = node->next;
        }
        return node;
    }
    bool remove(T const &e) {
        if (header == nullptr) {
            return false;
        } else {
            if (header->data == e) {
                delete header;
                header = nullptr;
                return true;
            }
        }
        auto node = header;
        while (node->next != nullptr) {
            if (node->next->data == e) {
                delete node->next;
                node->next = nullptr;
                return true;
            }
            node = node->next;
        }
        return false;
    }
};

template <typename T> class Hash {
private:
    List<T> **_bucket;

public:
    Hash() {
        _bucket = new List<T> *[MOD];
        for (int r = 0; r < MOD; ++r) {
            _bucket[r] = nullptr;
        }
    }

    bool put(int32_t n) {
        auto r = n % MOD;
        if (_bucket[r] != nullptr) {
            auto result = _bucket[r]->find(n);
            if (result == nullptr) {
                _bucket[r]->insert(n);
                return true;
            } else {
                return false;
            }
        } else {
            _bucket[r] = new List<T>();
            _bucket[r]->insert(n);
            return true;
        }
    }

    bool remove(int32_t n) {
        auto r = n % MOD;
        return (_bucket[r] == nullptr) ? false : _bucket[r]->remove(n);
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