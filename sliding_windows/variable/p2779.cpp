#include <vector>
#include <map>
#include <tuple>
#include <climits>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0;
        int maxLen = 0;
        for(int right = 0; right < nums.size(); right++){
            while(left <= right && (nums[right] - nums[left] > 2*k)){
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};

/* 差分
class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        map<int, int> diff;

        for (int x : nums) {
            diff[x - k]++;
            diff[x + k + 1]--;
        }

        int cur = 0, ans = 0;
        for (auto& [_, cnt] : diff) {
            cur += cnt;
            ans = max(ans, cur);
        }
        return ans;
    }
};
*/