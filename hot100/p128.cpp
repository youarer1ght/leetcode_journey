#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        int maxLength = 0;
        int currentLength = 1;
        for(int i = 1; i < temp.size(); i++){
            if(temp[i] == temp[i-1]){  // 跳过重复元素
                continue;
            }
            if(temp[i] == temp[i-1] + 1){
                currentLength++;
            } else {
                maxLength = max(maxLength, currentLength);
                currentLength = 1;
            }
        }
        return max(maxLength, currentLength);
    }
};