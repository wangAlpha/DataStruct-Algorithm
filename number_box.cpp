#include <cstdio>
#include <iostream>

uint32_t array[100000];
int main() {
    int n;
    for (std::cin >> n; n > 0; --n) {
        int op, number;
        scanf("%d%d", &op, &number);
        if (op == 1) {
            if (array[number] == 0) {
                array[number] = 1;
                printf("Succeeded\n");
            } else {
                printf("Failed\n");
            }
        } else {
            if (array[number] == 1) {
                array[number] = 0;
                printf("Succeeded\n");
            } else {
                printf("Failed\n");
            }
        }
    }
    return 0;
}