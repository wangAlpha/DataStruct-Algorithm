#pragma once

#include <iostream>
// 并查集
class UnionFind {
private:
    // 存储节点
    int *_id;
    // 存储每棵树的大小信息
    int *_sz;
    size_t _size;

public:
    UnionFind(int const &n) {
        _size = n;
        _id = new int[n];
        _sz = new int[n];
        for (int i = 0; i < n; ++i) {
            _id[i] = i;
            _sz[i] = 1;
        }
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
        for (int i = 0; i < 10; ++i) {
            printf("%d ", _id[i]);
        }
        printf("\n");
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
#include <#include <cstdio>
#include <cstdio>
iostream>
// 并查集
class UnionFind {
private:
    // 存储节点
    int *_id;
    // 存储每棵树的大小信息
    int *_sz;
    size_t _size;

public:
    UnionFind(int const &n) {
        _size = n;
        _id = new int[n];
        _sz = new int[n];
        for (int i = 0; i < n; ++i) {
            _id[i] = i;
            _sz[i] = 1;
        }
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
        for (int i = 0; i < 10; ++i) {
            printf("%d ", _id[i]);
        }
        printf("\n");
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