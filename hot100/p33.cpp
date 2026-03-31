#include <vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) return mid;
            
            // 判断哪一半是有序的
            if (nums[left] <= nums[mid]) {  // 左半部分有序
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;  // target 在左半
                } else {
                    left = mid + 1;   // target 在右半
                }
            } else {  // 右半部分有序
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;   // target 在右半
                } else {
                    right = mid - 1;  // target 在左半
                }
            }
        }
        
        return -1;
    }
};