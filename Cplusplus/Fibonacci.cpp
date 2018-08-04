class Solution {
public:
    int Fibonacci(int n) {
        int array[] = {0, 1};
        if (n < 2) {
            return array[n];
        }
        while (n >= 2) {
            array[0] = array[0] + array[1];
            array[1] = array[0] + array[1];
            n -= 2;
        }
        return array[n];
    }
};


