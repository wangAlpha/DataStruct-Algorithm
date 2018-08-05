#include <algorithm>
#include <iostream>
#include <random>

template <typename T> struct ListNode {
    T data;
    ListNode<T> *succ;
    ListNode(T const e) : data(e), succ(nullptr) {}
};

template <typename T> class List {
    ListNode<T> *head;

public:
    List() { head = nullptr; }
    void insert(T const &e) {
        if (head == nullptr) {
            head = new ListNode<T>(e);
            return;
        }
        auto l = head;
        for (; l->succ != nullptr; l = l->succ) {
        }
        l->succ = new ListNode<T>(e);
    }

    ListNode<T> *insert(ListNode<T> *&head, ListNode<T> *&list,
                        ListNode<T> *node) {
        if (head == nullptr) {
            head = node;
            list = head->succ;
            return list;
        }
        list->succ = node;
        return list->succ;
    }

    void insertSort() {
        auto h = head;
        ListNode<T> *new_head = nullptr;
        ListNode<T> *p = new_head;
        while (h) {
            auto node = h;
            h = h->succ;
            p = insert(new_head, p, h);
        }
        head = new_head;
    }
    void visit() {
        for (auto l = head; l != nullptr; l = l->succ) {
            std::cout << l->data << ' ';
        }
        std::cout << '\n';
    }
};

int main() {
    List<int> list;
    int arr[10];
    std::default_random_engine rand;
    std::for_each(arr, arr + 10, [&](int &e) { e = rand(); });
    std::for_each(arr, arr + 10, [](int e) { std::cout << e << ' '; });
    for (auto const &e : arr) {
        list.insert(e);
    }
    std::cout << '\n';
    list.visit();
    list.insertSort();
    list.visit();
    return 0;
}