#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.front() < nums.back()){
            return nums.front();
        }
        int left = 0;
        int right = nums.size() - 1;
        while(left < right){
            int mid = left + (right - left) / 2;
            if(nums[mid] > nums[right]){
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return nums[left];
    }
};

int main(){
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    Solution s;
    int result = s.findMin(nums);
    cout << result;
}