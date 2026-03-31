#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int sz = nums.size();
        for(int i = sz - 1; i > 0; i--){
            if(nums[i] > nums[i-1]){
                sort(nums.begin() + i, nums.end());
                auto it = upper_bound(nums.begin() + i, nums.end(), nums[i-1]);
                swap(*it, nums[i-1]);
                return;
            }
        }
        reverse(nums.begin(), nums.end());
        return;
    }
};