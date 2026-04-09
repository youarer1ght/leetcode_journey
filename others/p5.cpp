#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        pair<int, int> result = {0, 1}; // begin(), len
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        // len = 1
        for(int i = 0; i < n; i++){
            dp[i][i] = true;
        }
        // len = 2
        for(int i = 0; i < n-1; i++){
            dp[i][i+1] = (s[i] == s[i+1]);
            if(dp[i][i+1]){
                result = {i, 2};
            }
        }
        // len > 2
        for(int L = 2; L < n; L++){
            for(int i = 0; i < n - L; i++){
                dp[i][i+L] = (dp[i+1][i+L-1] && (s[i] == s[i+L]));
                if(dp[i][i+L]){
                    result = {i, L+1};
                }
            }
        }
        return s.substr(result.first, result.second);
    }
};