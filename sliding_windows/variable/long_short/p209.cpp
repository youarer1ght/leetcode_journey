#include <vector>
#include <climits>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int currSum = 0;
        int shortest = INT_MAX;
        for(int right = left; right < n; right++){
            currSum += nums[right];
            if(currSum < target){
                continue;
            }
            while(currSum - nums[left] >= target){
                currSum -= nums[left];
                left++;
            }
            shortest = min(shortest, right - left + 1);
        }
        return shortest == INT_MAX ? 0 : shortest;
    }
};