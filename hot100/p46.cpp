#include <vector>
#include <string>
using namespace std;
class Solution {
private:
    vector<vector<int>> result;
    vector<int> curr;
    void backtrace(vector<int>& nums, vector<vector<int>>& result, vector<int>& curr){
        if(nums.empty()){
            result.push_back(curr);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            int num = nums[i];
            curr.push_back(num);
            nums.erase(nums.begin() + i);
            backtrace(nums, result, curr);
            nums.insert(nums.begin() + i, num); // 插回原位
            curr.pop_back();    // 弹出当前数字
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        result.clear();
        curr.clear();
        backtrace(nums, result, curr);
        return result;
    }
};