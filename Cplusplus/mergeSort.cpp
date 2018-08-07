#include <iostream>
// 合并数组
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

template <typename T> void quickSort(T arr[], int lo, int hi) {
    if (hi - lo < 2) {
        return;
    }
    auto mi = parition(arr, lo, hi - 1);
    quickSort(arr, lo, mi);
    quickSort(arr, mi + 1, hi);
}
template <typename T> void merge(T arr[], int lo, int mi, int hi) {
    int lb = mi - lo;
    auto B = new T[lb];
    for (int i = 0; i < lb; ++i) {
        B[i] = arr[lo + i];
    }
    int lc = hi - mi;
    auto C = arr + mi;

    for (int i = 0, j = 0; (i < lb) || (j < lc);) {
        if ((i < lb) && (!(j < lc) || (B[i] <= C[j]))) {
            arr[lo++] = B[i++];
        }
        if ((j < lc) && (!(i < lb) || (C[j] < B[i]))) {
            arr[lo++] = C[j++];
        }
    }
    delete[] B;
}

void mergeSort(int arr[], int lo, int hi) {
    if (hi - lo < 2) {
        return;
    }

    auto mi = (hi + lo) / 2;
    mergeSort(arr, lo, mi);
    mergeSort(arr, mi, hi);
    merge(arr, lo, mi, hi);
}

int main(int argc, char const *argv[]) {
    int n;
    std::cin >> n;
    auto arr = new int[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    mergeSort(arr, 0, n);
    // quickSort()
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    std::cout << std::endl;
    delete[] arr;
    return 0;
}
