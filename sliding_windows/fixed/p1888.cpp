#include <string>
using namespace std;
class Solution {
public:
    int minFlips(string s) {
        // init
        int len = s.length();
        int count0 = 0; // 0 开头
        int count1 = 0; // 1 开头
        for(int i = 0; i < len; i++){
            if(i % 2){
                if(s[i] != '0'){
                    count0++;
                } else {
                    count1++;
                }
            } else {
                if(s[i] != '1'){
                    count0++;
                } else {
                    count1++;
                }
            }
        }
        int result = min(count0, count1);
        // loop
        string prev = s;
        string curr;
        for(int i = 1; i < len; i++){
            curr = prev.substr(1, len - 1);
            curr += prev[0];
            prev = curr;
            if()
        }
    }
};