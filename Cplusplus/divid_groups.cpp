#include <iostream>
#include <cstdio>


bool check(int64_t const &d, int const &n, int const &m, int const number[]) {
    int64_t sum = 0;
    int cnt = 1;

    for (int i = 0; i < n; ++i) {
        if (number[i] > d) {
            return false;
        }
        sum += number[i];
        if (sum > d) {
            sum = number[i];
            cnt += 1;
        }
    }

    return cnt <= m;
}

int64_t getAnswer(int const numbers[], int const &n, int const &m) {
    int64_t lo = 1, hi = 0;
    for (int i = 0; i < n; ++i) {
        hi += numbers[i];
    }

    while (lo < hi) {
        int64_t const mid = (lo + hi) >> 1;
        if (check(mid, n, m, numbers)) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    return hi + 1;
}

int main(int argc, char const *argv[]) {
    int n, m;
    std::cin >> n >> m;
    auto numbers = new int[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }
    std::cout << getAnswer(numbers, n, m) << std::endl;
    delete[] numbers;
    return 0;
}
