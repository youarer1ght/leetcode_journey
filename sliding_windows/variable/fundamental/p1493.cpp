#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        int maxLen = 0;
        int currLen = 0;
        for(int i = 0; i < n; i++){
            currLen++;
            if(nums[i] == 0){
                count++;
            }
            while(count > 1){
                currLen--;
                if(nums[i-currLen] == 0){
                    count--;
                }
            }
            maxLen = max(maxLen, currLen - 1);
        }
        return maxLen;
    }
};