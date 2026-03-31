#include <string>
using namespace std;
class Solution {
public:
    int maxScore(string s) {
        int len = s.length();
        int num0 = 0;
        int num1 = 0;
        for(char c: s){
            if(c == '1'){
                num1++;
            }
        }
        if(s[0] == '0'){
            num0++;
        } else {
            num1--;
        }
        int sum = num0 + num1;
        for(int i = 1; i < len - 1; i++){
            if(s[i] == '0'){
                num0++;
                sum = max(sum, num0 + num1);
            } else {
                num1--;
            }
        }
        return sum;
    }
};