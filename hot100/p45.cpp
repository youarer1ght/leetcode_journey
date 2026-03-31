#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;

        int jumps = 0;  // 跳跃次数
        int end = 0;    // 当前跳跃的边界
        int farthest = 0;   // 当前跳跃能到达的最远位置

        for (int i = 0; i < n - 1; i++) {
            farthest = max(farthest, i + nums[i]);

            if (i == end) {  // 到达当前跳跃的边界，必须再跳一次
                jumps++;
                end = farthest;
            }
        }

        return jumps;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {2, 3, 0, 1, 4};
    int result = solution.jump(nums);
    // 输出结果
    cout << "Minimum jumps: " << result << endl;
    return 0;
}