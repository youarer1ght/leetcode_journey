#include <iostream>
class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) {
            unsigned int carry = (unsigned int)(a & b) << 1;
            a = a ^ b;
            b = carry;
        }
        return a;
    }
};

int main(){
    Solution s;
    int a = 0x11;
    int b = 0x01;
    std::cout << s.getSum(a, b);
}