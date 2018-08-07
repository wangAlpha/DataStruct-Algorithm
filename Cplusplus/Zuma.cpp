#include <iostream>

struct ListNode {
    char data;
    ListNode *succ;
    ListNode(int const ch, ListNode *next = nullptr) : data(ch), succ(next) {}
};

void insert(ListNode *header, ListNode *tailer, int const n, char const ch) {
    auto node = header;
    for (auto i = 0; i < n && node != tailer; ++i) {
        node = node->succ;
    }
    node->succ = new ListNode(ch, node->succ);
}

void merge(ListNode *header, ListNode *tailer) {
    auto node = header->succ;
    while (node != tailer) {
        if (node->data == node->succ->data &&
            node->data == node->succ->succ->data && node->succ != tailer) {
            auto old_node = node;
            auto old_data = node->data;
            while (node->data == old_data && node != tailer) {
                node->data = node->succ->succ->data;
                node->succ = node->succ->succ->succ;
            }
            if (node != tailer) {
                merge(header, tailer);
            }
        }
        node = node->succ;
    }
}

void visitList(ListNode *header, ListNode *tailer) {
    if (header->succ == tailer) {
        std::cout << '-';
    } else {
        auto node = header->succ;
        while (node != tailer) {
            std::cout << node->data << ' ';
            node = node->succ;
        }
    }
    std::cout << std::endl;
}

int main(int argc, char const *argv[]) {
    char ch;
    auto tailer = new ListNode(0);
    auto header = new ListNode(0, tailer);
    auto node = header;
    // while ((ch = getchar()) != EOF) {
    for (int i = 0; i < 5; ++i) {
        std::cin >> ch;
        // node->data = ch;
        node->succ = new ListNode(ch, tailer);
        node = node->succ;
    }
    visitList(header, tailer);
    // getchar();
    int n, op;
    std::cin >> n;
    std::cout << "> ";
    for (auto i = 0; i < n; ++i) {
        std::cin >> op >> ch;
        insert(header, tailer, op, ch);
        visitList(header, tailer);
        merge(header, tailer);
        visitList(header, tailer);
    }
    visitList(header, tailer);
    return 0;
}
