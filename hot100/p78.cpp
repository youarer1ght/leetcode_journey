#include <vector>
using namespace std;
class Solution {
private:
    vector<vector<int>> result;
    vector<int> curr;
    
    void backtrack(vector<int>& nums, int start) {
        // 每进入一层，当前路径就是一个子集
        result.push_back(curr);
        
        for (int i = start; i < nums.size(); i++) {
            curr.push_back(nums[i]);
            backtrack(nums, i + 1);  // 从下一个元素开始，避免重复
            curr.pop_back();
        }
    }
    
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        result.clear();
        curr.clear();
        backtrack(nums, 0);
        return result;
    }
};