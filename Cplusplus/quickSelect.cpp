#include <algorithm>
#include <cstdio>
#include <iostream>

void quickSelect(int arr[], int lo, int hi, int k) {
    for (int lo = 0; lo < hi; ++lo) {
        int i = lo, j = hi;
        int pivot = arr[lo];
        while (i < j) {
            while ((i < j) && (pivot <= arr[j])) {
                ++j;
            }
            arr[i] = arr[j];
            while ((i < j) && (pivot >= arr[i])) {
                ++i;
            }
            arr[j] = arr[i];
        }
        arr[i] = pivot;
        if (k <= i) {
            hi = i - 1;
        }
        if (k >= i) {
            lo = i + 1;
        }
    }
}

int main(int argc, char const *argv[]) {
    int n, k;
    std::cin >> n >> k;
    int *arr = new int[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
    quickSelect(arr, 0, n, k);
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;

    return 0;
}
