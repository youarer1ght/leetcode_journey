#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows == 0){
            return {};
        }
        vector<vector<int>> result;
        result.push_back({1});  // 初始化第一行
        for(int i = 1; i < numRows; i++){
            vector<int> prev = result.back();
            vector<int> curr(i+1, 1);
            for(int j = 1; j < i; j++){
                curr[j] = prev[j-1] + prev[j];
            }
            result.push_back(curr);
        }
        return result;
    }
};