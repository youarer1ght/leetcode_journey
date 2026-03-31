#include <string>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // 将字典转换为 unordered_set 提高查找效率
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        
        int n = s.length();
        vector<bool> dp(n + 1, false);
        dp[0] = true;  // 空字符串可以被拆分
        
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                // 如果 s[0:j] 可拆分，且 s[j:i] 在字典中
                if (dp[j] && dict.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;  // 找到一种拆分即可
                }
            }
        }
        
        return dp[n];
    }
};