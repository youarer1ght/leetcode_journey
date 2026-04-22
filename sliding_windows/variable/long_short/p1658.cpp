#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        // 转化成 sum(中间) = total - x
        int n = nums.size();
        int left = 0, right = 0;
        int maxLen = -1;
        long total = 0;
        for(int i = 0; i < n; i++){
            total += nums[i];
        }
        if(total < x){
            return -1;
        }
        long target = total - static_cast<long>(x);
        long curSum = 0;
        for(int right = 0; right < n; right++){
            curSum += nums[right];
            while(left < right && curSum > target){
                curSum -= nums[left];
                left++;
            }
            if(curSum == target){
                maxLen = max(maxLen, right - left + 1);
            }
        }
        return maxLen < 0 ? -1 : (n - maxLen);
    }
};

int main(){
    vector<int> nums = {3,2,20,1,1,3};
    int x = 10;
    Solution s;
    int res = s.minOperations(nums, x);
    cout << res;
}