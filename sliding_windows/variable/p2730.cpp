#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        if(s.length() == 1){
            return 1;
        }
        // init
        int left = 0;
        int dIndex = 0;    // 记录重复位置的右侧
        int maxLen = 1;
        for(int right = 1; right < s.length(); right++){
            if(s[right] == s[right - 1]){
                if(dIndex){
                    left = dIndex;
                }
                dIndex = right;
            }
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};