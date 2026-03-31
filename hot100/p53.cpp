#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];  // 最大子数组和，初始化为第一个元素
        int cur = nums[0];     // 当前子数组和，初始化为第一个元素

        // 从第二个元素开始遍历
        for (int i = 1; i < nums.size(); i++) {
            // 关键决策：是继续扩展当前子数组，还是从当前元素重新开始
            // 如果当前元素比"当前子数组和+当前元素"更大，说明前面的子数组和是负数（拖累）
            // 此时放弃前面的子数组，从当前元素重新开始
            cur = max(nums[i], cur + nums[i]);

            // 更新最大子数组和
            maxSum = max(maxSum, cur);
        }

        return maxSum;
    }
};