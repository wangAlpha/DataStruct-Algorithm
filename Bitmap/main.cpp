#include <iostream>
#include "Bitmap.h"

int main(int argc, char const *argv[]) {
    Bitmap lazyRemoval(10000);
    for (int i = 0; i < 10000; ++i) {
        lazyRemoval.set(i);
        std::cout << "set: " << i<< ' ' << lazyRemoval.get(i) << std::endl;
        lazyRemoval.remove(i);
        std::cout << "remove: " << i << ' ' << lazyRemoval.get(i) << std::endl;
    }
    return 0;
}
