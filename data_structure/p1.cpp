#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> sorted_nums = nums;
        sort(sorted_nums.begin(), sorted_nums.end());
        int left = 0;
        int right = nums.size() - 1;
        while(left < right){
            int sum = sorted_nums[left] + sorted_nums[right];
            if(sum == target){
                break;
            } else if(sum > target){
                right--;
            } else {
                left++;
            }
        }
        left = find(nums.begin(), nums.end(), sorted_nums[left]) - nums.begin();
        right = find(nums.rbegin(), nums.rend(), sorted_nums[right]) - nums.rbegin();
        right = nums.size() - right - 1;
        return {left, right};
    }
};