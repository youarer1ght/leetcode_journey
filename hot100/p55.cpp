#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int farthest = 0;
        for(int i = 0; i <= farthest && i < n; i++){
            farthest = max(farthest, i + nums[i]);
        }
        return farthest + 1 >= n;
    }
};