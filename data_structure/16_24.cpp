#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<vector<int>> pairSums(vector<int>& nums, int target) {
        unordered_map<int, int> option; // nums[i], freq
        vector<vector<int>> result;
        for(int i = 0; i < nums.size(); i++){
            if(option[target - nums[i]] > 0){
                result.push_back({target - nums[i], nums[i]});
                option[target - nums[i]]--;
            } else {
                option[nums[i]]++;
            }
        }
        return result;
    }
};