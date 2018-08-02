#include <stdio.h>

#define INIT_CAPACITY 1024
template <typename T> class Stack {
  private:
    T *data;
    size_t len, capacity;

  public:
    Stack() {
        len = 0;
        capacity = INIT_CAPACITY;
        data = new T[capacity];
    }
    void push(const T e) {
        data[len++] = e;
        if (len >= capacity - 1) {
            dealloc();
        }
    }
    T pop() { return data[--len]; }
    T top() { return data[len - 1]; }
    void dealloc() {
        capacity <<= 1;
        auto old_elem = data;
        data = new T[capacity];
        for (auto i = 0; i < len; ++i) {
            data[i] = old_elem[i];
        }
        delete old_elem;
    }
    bool empty() { return len == 0; }
};

struct BinNode {
    BinNode *left;
    BinNode *right;
    int data;
    BinNode(BinNode *l = NULL, BinNode *r = NULL, int e = 0)
        : left(l), right(r), data(e) {}
};

class Tree {
    BinNode *root;

  public:
    Tree() { root = nullptr; }

    BinNode *insert_node(BinNode *root, BinNode *node) {
        if (root == nullptr) {
            return node;
        }
        if (node->data < root->data) {
            root->left = insert_node(root->left, node);
        } else {
            root->right = insert_node(root->right, node);
        }
        return root;
    }

    void insert(int e) {
        if (root == NULL) {
            root = new BinNode(NULL, NULL, e);
        } else {
            auto node = root;
            while (true) {
                if (node->data < e) {
                    if (node->right == NULL) {
                        node->right = new BinNode(NULL, NULL, e);
                        return;
                    }
                    node = node->right;
                } else {
                    if (node->left == NULL) {
                        node->left = new BinNode(NULL, NULL, e);
                        return;
                    }
                    node = node->left;
                }
            }
        }
    }

    void previsit(BinNode *root) {
        if (!root) {
            return;
        }
        Stack<BinNode *> s;
        s.push(root);
        while (!s.empty()) {
            auto node = s.pop();
            printf("%d ", node->data);
            if (node->right) {
                s.push(node->right);
            }
            if (node->left) {
                s.push(node->left);
            }
        }
    }

    void preOrder() {
        previsit(root);
        printf("\n");
    }

    void postvisit(BinNode *root) {
        if (!root) {
            return;
        }
        Stack<BinNode *> s;
        Stack<int> ss;
        s.push(root);
        while (!s.empty()) {
            auto node = s.top();
            ss.push(node->data);
            s.pop();
            if (node->left) {
                s.push(node->left);
            }
            if (node->right) {
                s.push(node->right);
            }
        }
        for (int i = ss.len - 1; i >= 0; --i) {
            printf("%d ", ss.data[i]);
        }
    }
    void postOrder() {
        postvisit(root);
        printf("\n");
    }
    void mivisit(BinNode *root) {
        if (root != nullptr) {
            mivisit(root->left);
            printf("%d ", root->data);
            mivisit(root->right);
        }
    }
    void miOrder() {
        mivisit(root);
        printf("\n");
    }
};

int main() {
    int n = 0;
    Tree t;
    scanf("%d", &n);

    for (auto i = 0; i < n; ++i) {
        int e;
        scanf("%d", &e);
        t.insert(e);
    }
    t.preOrder();
    t.postOrder();
    return 0;
}