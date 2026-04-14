#include <vector>
using namespace std;
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) sum += num;
        
        // 总和为奇数，不可能平分
        if (sum % 2 != 0) return false;
        
        int target = sum / 2;
        int n = nums.size();
        
        // dp[i][j]：前 i 个数能否凑出和为 j
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
        
        // 初始化：凑出和为 0 总是可以的
        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= target; j++) {
                if (j < nums[i - 1]) {
                    // 装不下当前数
                    dp[i][j] = dp[i - 1][j];
                } else {
                    // 不装 或 装
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
                }
            }
        }
        
        return dp[n][target];
    }
};