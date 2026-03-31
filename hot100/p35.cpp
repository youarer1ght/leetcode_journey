#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        auto it = lower_bound(nums.begin(), nums.end(), target);
        if((it == nums.end()) || (*it != target)){
            it = nums.insert(it, target);   
        }
        return it - nums.begin();
    }
};