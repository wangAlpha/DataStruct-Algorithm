#include <cstdio>

int main() {
    int number, count;
    scanf("%d %d", &number, &count);
    int *zone = new int[number];
    for (auto i = 0; i < number; ++i) {
        scanf("%d", &zone[i]);
    }
    // for (int i = 0; i < number; ++i) {
    //     printf("%d ", zone[i]);
    // }
    // printf("\n");
    int min, max;
    for (auto i = 0; i < count; ++i) {
        int min_index = 0, max_index = 0;
        scanf("%d%d", &min, &max);
        for (int index = 0; index < number; ++index) {
            if (min >= zone[index]) {
                min_index = index;
                break;
            }
        }
        for (int index = number - 1; index >= 0; --index) {
            if (max >= zone[index]) {
                max_index = index;
                break;
            }
        }
        if (max_index <= min_index) {
            printf("0");
        } else {
            // printf("min_index: %d, max_index: %d\n", max_index, min_index);
            printf("%d\n", max_index - min_index - 1);
        }
    }

    return 0;
}