#include <vector>
using namespace std;
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int num1 = 0;
        for(int num: nums){
            if(num == 1){
                num1++;
            }
        }
        // init
        int num0 = 0;
        for(int i = 0; i < num1; i++){
            if(nums[i] == 0){
                num0++;
            }
        }
        int minNum0 = num0;
        // loop
        for(int i = num1; i < n; i++){
            // pop
            if(nums[i-num1] == 0){
                num0--;
            }
            // push
            if(nums[i] == 0){
                num0++;
            }
            minNum0 = min(minNum0, num0);
        }
        for(int i = 0; i < num1; i++){
            // pop
            if(nums[n - num1 + i] == 0){
                num0--;
            }
            // push
            if(nums[i] == 0){
                num0++;
            }
            minNum0 = min(minNum0, num0);
        }
        return minNum0;
    }
};