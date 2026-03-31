#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int ptr0 = 0;
        int ptr2 = nums.size() - 1;
        int i = 0;
        
        while (i <= ptr2) {  // 关键：只遍历到 ptr2
            if (nums[i] == 0) {
                swap(nums[ptr0], nums[i]);
                ptr0++;
                i++;  // 从前面交换来的不可能是 2（因为 ptr0 之前已经处理过）
            } 
            else if (nums[i] == 2) {
                swap(nums[ptr2], nums[i]);
                ptr2--;
                // 注意：这里不 i++，因为交换来的可能是 0，需要再次检查
            } 
            else {  // nums[i] == 1
                i++;
            }
        }
    }
};