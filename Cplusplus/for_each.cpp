#include <iostream>

template <typename T, typename Fn> void for_each(T *begin, T *end, Fn fun) {
    for (; begin != end; ++begin) {
        fun(*begin);
    }
}

int main(int argc, char const *argv[]) {
    int array[] = {1, 2, 3, 4, 4, 5, 5};
    int _array[] = {5, 4, 3, 2, 3, 1, 0};
    for_each(array, array + 6, [&_array](int e) {
        _array[0] = 0;
        std::cout << e << ' ';
    });
    std::cout << std::endl;
    for_each(_array, _array + 6, [](int e) { std::cout << e << ' '; });
    std::cout << std::endl;
    return 0;
}
