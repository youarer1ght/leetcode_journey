#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        int n = nums.size();
        if (n < k) return 0;
        
        unordered_map<int, int> freq;  // 值 -> 出现次数
        long long sum = 0;
        long long maxSum = 0;
        
        // 初始化第一个窗口
        for (int i = 0; i < k; i++) {
            sum += nums[i];
            freq[nums[i]]++;
        }
        
        // 检查第一个窗口的不同元素个数
        if (freq.size() >= m) {
            maxSum = sum;
        }
        
        // 滑动窗口
        for (int i = k; i < n; i++) {
            // 移出左边元素
            int left = nums[i - k];
            sum -= left;
            freq[left]--;
            if (freq[left] == 0) {
                freq.erase(left);
            }
            
            // 加入右边元素
            int right = nums[i];
            sum += right;
            freq[right]++;
            
            // 检查条件
            if (freq.size() >= m) {
                maxSum = max(maxSum, sum);
            }
        }
        
        return maxSum;
    }
};