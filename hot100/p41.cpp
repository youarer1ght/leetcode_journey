#include <vector>
#include <cmath>
#include <iostream>
using namespace std;
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] <= 0){
                nums.erase(nums.begin() + i);
                i--;
            }
        }
        for(int i = 0; i < nums.size(); i++){
            if(abs(nums[i]) <= nums.size() && nums[abs(nums[i]) - 1] > 0){
                nums[abs(nums[i])-1] = -nums[abs(nums[i])-1];
            }
        }
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0){
                return i + 1;
            }
        }
        return nums.size() + 1;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1, 2, 0};
    cout << s.firstMissingPositive(nums);
}