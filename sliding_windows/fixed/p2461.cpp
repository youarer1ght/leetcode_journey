#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        long long sum = 0;
        // init
        for(int i = 0; i < k; i++){
            sum += nums[i];
            freq[nums[i]]++;
        }
        long long maxSum = 0;
        if(freq.size() == k){
            maxSum = sum;
        }
        // loop
        for(int i = k; i < nums.size(); i++){
            sum = sum - nums[i-k] + nums[i];
            freq[nums[i-k]]--;
            if(freq[nums[i-k]] == 0){
                freq.erase(nums[i-k]);
            }
            freq[nums[i]]++;
            if(freq.size() == k){
                maxSum = max(maxSum, sum);
            }
        }
        return maxSum;
    }
};