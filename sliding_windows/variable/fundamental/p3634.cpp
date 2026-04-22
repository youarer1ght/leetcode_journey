#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        // init
        int f = 0;
        int maxLen = 1;
        int currLen = 1;
        for(int i = 1; i < nums.size(); i++){
            while(f <= i && (long long)nums[i] > (long long)k * nums[f]){
                f++;
            }
            maxLen = max(maxLen, i - f + 1);
        }
        return nums.size() - maxLen;
    }
};