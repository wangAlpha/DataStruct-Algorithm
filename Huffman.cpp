#include <cstdio>

template <typename T> struct BinNode {
    BinNode *left;
    BinNode *right;
    T *e;
};

template <typename T> class BinTree {
  private:
    BinNode *_root;

  public:
    void insert(T const &e) {}
    void visit() {}
};

int main(int argc, char const *argv[]) {
    int array[] = {10, 8, 3, 4, 5};

    return 0;
}
