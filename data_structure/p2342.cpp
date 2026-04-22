#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
private:
    int digitSum(int num){
        int count = 0;
        while(num > 0){
            count += num % 10;
            num /= 10;
        }
        return count;
    }
public:
    int maximumSum(vector<int>& nums) {
        // key 数位和 value 最大值
        unordered_map<int, int> dSum;   // \Sigma{digit}, max(nums[i])
        int n = nums.size();
        int maxSum = -1;
        for(int i = 0; i < n; i++){
            int val = dSum[digitSum(nums[i])];
            if(val > 0){
                maxSum = max(maxSum, val + nums[i]);
            }
            if(nums[i] > val){
                dSum[digitSum(nums[i])] = nums[i];
            }
        }
        return maxSum;
    }
};

int main(){
    Solution s;
    vector<int> nums = {18, 43, 36, 13, 7};
    cout << s.maximumSum(nums);
}