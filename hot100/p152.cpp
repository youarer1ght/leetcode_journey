#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxProd = nums[0];
        int minProd = nums[0];
        int ans = nums[0];

        for (int i = 1; i < n; i++) {
            // 保存上一次的最大值，因为 minProd 更新会覆盖
            int tempMax = maxProd;
            int tempMin = minProd;

            maxProd = max({nums[i], tempMax * nums[i], tempMin * nums[i]});
            minProd = min({nums[i], tempMax * nums[i], tempMin * nums[i]});

            ans = max(ans, maxProd);
        }
        return ans;
    }
};