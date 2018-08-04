#include <cstdio>
#include <iostream>

template <typename T> void swap(T &a, T &b) {
    T e = a;
    a = b;
    b = e;
}

// 并查集
class UnionFind {
private:
    // 存储节点
    int _id[500000];
    // 存储每棵树的大小信息
    int _sz[500000];
    // int *_id;
    // int *_sz;
    size_t _size;
    void init(int const &n) {
        _size = n + 1;
        // _id = new int[_size];
        // _sz = new int[_size];
        for (int i = 0; i < n; ++i) {
            // _id[i] = i;
            // _sz[i] = 1;
            *(_id + i) = i;
            *(_sz + i) = 1;
        }
    }

public:
    UnionFind(int const &n) {
        // _id = new int[n];
        // _sz = new int[n];
        init(n);
    }
    void reset(int n) { init(n); }
    ~UnionFind() {
        // delete[] _id;
        // delete[] _sz;
    }
    void Union(int const &p, int const &q) {
        int pID = find(p);
        int qID = find(q);
        if (pID == qID) {
            return;
        }
        if (_sz[pID] > _sz[qID]) {
            _id[qID] = pID;
            _sz[pID] += _sz[qID];
        } else {
            _id[pID] = qID;
            _sz[qID] += _sz[pID];
        }
        --_size;
    }

    int find(int p) {
        while (p != _id[p]) {
            _id[p] = _id[_id[p]];
            p = _id[p];
        }
        return p;
    }

    bool connected(int const &p, int const &q) { return find(p) == find(q); }
    int size() const { return _size; }
};
UnionFind set(500000);
// int record[50000][3];

bool getAnswear(int record[][3], int n) {
    auto index = n;

    auto result = true;
    int last = index - 1;
    for (int i = index - 1; i >= 0; --i) {
        if (record[i][2] == 1) {
            last = i;
            break;
        }
    }
    for (int i = 0; i < last; ++i) {
        if (record[i][2] == 0) {
            swap(record[i][0], record[last][0]);
            swap(record[i][1], record[last][1]);
            swap(record[i][2], record[last][2]);
            --last;
        }
    }
    for (int i = 0; i < index; ++i) {
        if (record[i][2] == 1) {
            set.Union(record[i][0], record[i][1]);
        } else {
            if (set.connected(record[i][0], record[i][1])) {
                result = false;
                break;
            }
        }
    }
    return result;
}

int main(int argc, char const *argv[]) {
    int T;
    scanf("%d", &T);
    for (auto i = 0; i < T; ++i) {
        int n, m;
        scanf("%d %d", &n, &m);
        // 重置集合
        set.reset(500000);
        auto record = new int[m][3];
        int index = 0;
        for (int j = 0; j < m; ++j) {
            int a, b, e;
            scanf("%d %d %d", &a, &b, &e);
            record[index][0] = a;
            record[index][1] = b;
            record[index][2] = e;
            ++index;
        }
        auto result = getAnswear(record, index);
        printf("%s\n", result ? "Yes" : "No");
        delete[] record;
    }
    return 0;
}
