#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq;
        int left = 0;
        int currSum = 0;
        int maxSum = 0;
        for(int i = 0; i < n; i++){
            freq[nums[i]]++;
            currSum += nums[i];
            while(left <= i && (freq[nums[i]] > 1)){
                freq[nums[left]]--;
                if(freq[nums[left]] == 0){
                    freq.erase(nums[left]);
                }
                currSum -= nums[left];
                left++;
            }
            maxSum = max(maxSum, currSum);
        }
        return maxSum;
    }
};