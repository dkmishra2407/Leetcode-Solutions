#include <cmath>

class Solution {
public:
    int add(int a, int b) {
        if (!b) {
            return a;
        }

        int sum = a ^ b;
        int carry = (a & b) << 1;

        return add(sum, carry);
    }
    int getSum(int a, int b) { return add(a, b); }
};
