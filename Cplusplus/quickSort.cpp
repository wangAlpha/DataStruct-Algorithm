#include <algorithm>
#include <cstdio>
#include <iostream>
#include <random>
#include <stack>
#include <vector>

// 快速排序 递归版与迭代版实现
// 测试表明，迭代版速度比递归版稍慢，内存占用大有较少减少

template <typename T> int parition(T arr[], int lo, int hi) {
    std::swap(arr[lo], arr[lo + rand() % (hi - lo + 1)]);
    int pivot = arr[lo];

    while (lo < hi) {
        while (lo < hi && arr[hi] >= pivot) {
            --hi;
        }
        arr[lo] = arr[hi];
        while (lo < hi && arr[lo] <= pivot) {
            ++lo;
        }
        arr[hi] = arr[lo];
    }
    arr[lo] = pivot;
    return lo;
}

struct Stack {
    int data[1024];
    int _size;
    Stack() { _size = 0; }
    void push(int const &e) { data[_size++] = e; }
    int pop() { return data[--_size]; }
    int top() { return data[_size - 1]; }
    bool empty() const { return _size == 0; }
};
Stack s;
template <typename T> void quickSort(T arr[], int lo, int hi) {
    if (hi - lo < 2) {
        return;
    }
    auto mi = parition(arr, lo, hi - 1);
    quickSort(arr, lo, mi);
    quickSort(arr, mi + 1, hi);
    // std::stack<int> s;

    // s.push(lo);
    // s.push(hi - 1);
    // while (!s.empty()) {
    //     hi = s.top();
    //     s.pop();
    //     lo = s.top();
    //     s.pop();
    //     auto mi = parition(arr, lo, hi);
    //     if (mi - 1 > lo) {
    //         s.push(lo);
    //         s.push(mi);
    //     }
    //     if (mi + 1 < hi) {
    //         s.push(mi + 1);
    //         s.push(hi);
    //     }
    // }
}

int main(int argc, char const *argv[]) {
    int n;
    scanf("%d", &n);
    int *arr = new int[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    quickSort(arr, 0, n);
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    delete[] arr;
    return 0;
}
