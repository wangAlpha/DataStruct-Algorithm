#include <cstdio>
#include <iostream>
#include <memory>

int getAnswer(int *sequence, int const n) {
    int max_count = 0;
    for (int i = 0; i < n; ++i) {
    }
    return max_count;
}
int main(int argc, char const *argv[]) {
    int n, d;

    scanf("%d %d", &n, &n);

    auto sequence = new int[n];
    for (int i = 0; i < n; ++n) {
        scanf("%d", &sequence[i]);
    }
    for (int i = 0; i < n; ++i) {
        std::cout << sequence[i] << ' ';
    }
    std::cout << std::endl;
    printf("%d\n", getAnswer(sequence, n));
    return 0;
}
