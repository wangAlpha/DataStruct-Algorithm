#include <iostream>

template <typename T> void selectSort(T *arr, int lo, int hi) {
    auto maxIndex = hi;
    while (lo < hi) {
        for (int i = hi - 1; i >= lo; --i) {
            if (arr[i] > arr[maxIndex]) {
                maxIndex = i;
            }
        }
    }
}