#include <cstdio>
#include <iostream>

// 并查表
class DisjointSet {
private:
    //集合存储数组
    int *id;
    // 集合大小记录数组
    int *_sz;
    size_t _size;

public:
    DisjointSet(int n) {
        _size = n;
        id = new int[_size];
        _sz = new int[_size];
        for (int i = 0; i < _size; ++i) {
            id[i] = i;
            _sz[i] = 1;
        }
    }
    // 查询数值是否包含在这个集合中
    int find(int p) {
        p = p % 4000003;
        while (p != id[p]) {
            id[p] = id[id[p]];
            p = id[p];
        }
        return p;
    }
    // 集合合并
    bool join(int p, int q) {
        int pID = find(p);
        int qID = find(q);
        if (pID == qID) {
            return false;
        }

        if (_sz[pID] > _sz[qID]) {
            id[qID] = pID;
            _sz[pID] += _sz[qID];
        } else {
            id[pID] = qID;
            _sz[qID] += _sz[pID];
        }
        --_size;
        return true;
    }
    // 测试连通性
    bool connected(int const &p, int const &q) { return find(p) == find(q); }
    size_t size() const { return _size; }
};

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
    // ~Vector() { delete[] _elem; }

    void push_back(T const &e) { _elem[_size++] = e; }
    T pop_back() { return _elem[--_size]; }
    T &index(int n) { return _elem[n]; }
    size_t size() const { return _size; }
};

int main(int argc, char const *argv[]) {
    int n, m;
    scanf("%d%d", &n, &m);
    DisjointSet set(4000003);
    Vector<int> v1(n);
    Vector<int> v2(n);
    Vector<int> vec(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        v1.push_back(u);
        v2.push_back(v);
    }

    for (int i = m - 1; i >= 0; --i) {
        auto result = set.join(v1.pop_back(), v2.pop_back());
        if (result == true) {
            vec.push_back(i + 1);
        }
    }
    printf("%d\n", (int)vec.size());
    while (vec.size()) {
        printf("%d\n", vec.pop_back());
    }

    return 0;
}
