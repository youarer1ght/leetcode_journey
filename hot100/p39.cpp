#include <vector>
#include <algorithm>
using namespace std;
class Solution {
private:
    vector<vector<int>> result;
    vector<int> curr;
    void backtrack(vector<int>& candidates, int target, int start){
        if(target == 0){
            result.push_back(curr);
            return;
        }
        for(int i = start; i < candidates.size(); i++){
            if(candidates[i] > target){
                break;
            }
            curr.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        result.clear();
        curr.clear();
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0);
        return result;
    }
};