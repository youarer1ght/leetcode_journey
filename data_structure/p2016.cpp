#include <vector>
using namespace std;
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int minEle = nums[0];
        int maxDiff = -1;
        for(int i = 1; i < nums.size(); i++){
            minEle = min(minEle, nums[i-1]);
            if(nums[i] > minEle){
                maxDiff = max(maxDiff, nums[i] - minEle);
            }
        }
        return maxDiff;
    }
};