#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int maxLength = 0;
        int lastLength = 1; // 以每个元素结尾的最大长度
        int n = nums.size();
        for(int i = 1; i < n; i++){
            if(lastLength % 2){  // 奇数长度，等于加一
                if(nums[i] == nums[i-1] + 1){
                    lastLength++;
                } else {
                    lastLength = 1;
                }
            } else {    // 偶数，应该减一
                if(nums[i] == nums[i-1] - 1){
                    lastLength++;
                } else if(nums[i] == nums[i-1] + 1){    // 是否能在上一个元素开始计数
                    lastLength = 2;
                } else {
                    lastLength = 1;
                }
            }
            maxLength = max(maxLength, lastLength);
        }
        return maxLength == 1 ? -1 : maxLength;
    }
};