#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int fast, slow;
        int n = nums.size();
        for(fast = 0, slow = 0; fast < n; fast++){
            if(nums[fast] == 0){
                continue;
            }
            swap(nums[slow], nums[fast]);
            slow++;
        }
        return;
    }
};