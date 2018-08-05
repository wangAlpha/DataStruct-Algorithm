#include <algorithm>
#include <cstdio>
#include <iostream>
#define _DEBUG

template <typename T> class Vector {
    T *_elem;
    size_t _size;
    size_t len;

public:
    Vector(int n) {
        len = n;
        _size = 0;
        _elem = new T[len];
    }

    void push_back(T const &e) { _elem[_size++] = e; }
    T pop_back() { return _elem[--_size]; }
    T &index(int n) { return _elem[n]; }
    T &top() const { return _elem[_size - 1]; }
    size_t size() const { return _size; }
    bool empty() const { return size() == 0; }
};

template <typename T> struct BinNode {
    T data;
    int count;
    BinNode *left;
    BinNode *right;
    BinNode *parent;
    BinNode() {}
    BinNode(T const &e, BinNode<T> *lc = nullptr, BinNode<T> *rc = nullptr,
            BinNode<T> *p = nullptr)
        : data(e), count(1), left(lc), right(rc), parent(p) {}
};

template <typename T> class BST {
public:
    BST() {
        _root = nullptr;
        _size = 0;
    }

    // 查找节点，失败返回最近的那个节点
    BinNode<T> *search(T const &e) {
        if (!_root) {
            return _root;
        }
        auto node = _root;
        while (true) {
            if (e > node->data) {
                if (!node->right) {
                    return node;
                }
                node = node->right;
            } else if (e < node->data) {
                if (!node->left) {
                    return node;
                }
                node = node->left;
            } else {
                return node;
            }
        }
    }
    // 插入节点
    BinNode<T> *insert(T const &e) {
        auto hot = search(e); // 先找一下是不是有这个元素
        if (!hot) {
            return (_root = new BinNode<T>(e));
        }
        if (hot->data > e) {
            ++_size;
            hot->left = new BinNode<T>(e);
            hot->left->parent = hot;
        } else if (hot->data < e) {
            ++_size;
            hot->right = new BinNode<T>(e);
            hot->right->parent = hot;
        } else {
            // 重复元素
            hot->count++;
        }
        return hot;
    }

    // 直接后继
    BinNode<T> *succ(BinNode<T> *root) {
        root = root->right;
        while (root->left) {
            root = root->left;
        }
        return root;
    }

    // 移除节点
    bool remove(T const &e) {
        auto hot = search(e);
        if (!hot) {
            return false;
        }
        if (hot->data == e) {
            if (hot->count != 1) {
                hot->count--;
            } else {
                ++_size;
                if (hot->left) {
                    auto node = hot;
                    hot = hot->left;
                    delete node;
                } else if (hot->right) {
                    auto node = hot;
                    hot = hot->right;
                    delete node;
                } else {
                    auto node = succ(hot);
                    std::swap(node->data, hot->data);
                    if (node->right) {
                        auto p = node;
                        node = node->right;
                        delete node;
                    } else {
                        BinNode<T> **node = &(hot->parent);
                        (*node)->left = nullptr;
                    }
                }
            }
            return true;
        }
        return false;
    }

    // 查找前驱
    BinNode<T> *findPrev(T const &e) {
        if (!_root) {
            return _root;
        }
        auto node = search(e);
        if (node->data >= e) {
            if (node->left) {
                return node->left;
            } else if (node->parent) {
                return node->parent;
            }
        } else {
            return node->parent;
        }
        return (node->data > e) ? node->parent : node->left;
    }

    // 返回最小值
    T min() {
        if (!_root) {
            return 0;
        }
        auto node = _root;
        while (node->left) {
            node = node->left;
        }
        return node->data;
    }
    size_t size() const { return _size; }
    // 中序遍历
    void visitIn(BinNode<T> *root) {
        if (root) {
            visitIn(root->left);
            std::cout << root->data << ' ';
            visitIn(root->right);
        }
    }
    void visitIn2(BinNode<T> *root) {
        if (!root) {
            return;
        }
        Vector<BinNode<T> *> s((int)_size);
        auto node = root;
        while (true) {
            while (node) {
                s.push_back(node);
                node = node->left;
            }
            if (s.empty()) {
                return;
            }
            node = s.pop_back();
            std::cout << node->data << ' ';
            node = node->right;
        }
    }
    void traveIn() {
        visitIn2(_root);
        std::cout << std::endl;
        // visitIn(_root);
        // std::cout << std::endl;
    }

private:
    BinNode<T> *_root;
    size_t _size;
    void release(BinNode<T> *root) {
        if (root->parent != nullptr) {
            auto node = root->parent;
            delete root;
        }
    }
};

int main(int argc, char const *argv[]) {
    BST<int> tree;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int op, number;
        // std::cout << "-----------" << std::endl;
        scanf("%d", &op);
        switch (op) {
        case 1: {
            scanf("%d", &number);
            // std::cout << "insert " << number << std::endl;
            tree.insert(number);
        } break;
        case 2: {
            scanf("%d", &number);
            // std::cout << "remove " << number << std::endl;
            tree.remove(number);
        } break;
        case 3: {
            scanf("%d", &number);
            // std::cout << "search " << number << std::endl;
            auto result = tree.search(number);
            printf("%d\n", (result->data == number) ? result->count : 0);
        } break;
        case 4: {
            // std::cout << "min" << std::endl;
            printf("%d\n", tree.min());
        } break;
        case 5: {
            scanf("%d", &number);
            // std::cout << "findPrev" << std::endl;
            auto node = tree.findPrev(number);
            if (node) {
                printf("%d\n", node->data);
            } else {
                printf("None\n");
            }
        } break;
        default:
            break;
        }
        tree.traveIn();
    }
    return 0;
}
