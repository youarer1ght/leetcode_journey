#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        // init
        int n = s.length();
        int f = 0;
        int sumCost = 0;
        int maxLen = 0;
        for(int i = 0; i < n; i++){
            sumCost += abs(s[i] - t[i]);
            while(f <= i && sumCost > maxCost){
                sumCost -= abs(s[f] - t[f]);
                f++;
            }
            maxLen = max(maxLen, i - f + 1);
        }
        return maxLen;
    }
};