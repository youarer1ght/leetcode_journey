#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int x, y, z;
        vector<vector<int>> result;
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        for(x = 0; x < temp.size() - 2; x++){
            if (x > 0 && temp[x] == temp[x-1]){  // 跳过重复元素
                continue;
            }
            for(y = x + 1, z = temp.size() - 1; y < z;){
                if(y > x + 1 && temp[y] == temp[y-1]){  // 跳过重复元素
                    y++;
                    continue;
                }
                if(z < temp.size() - 1 && temp[z] == temp[z+1]){  // 跳过重复元素
                    z--;
                    continue;
                }
                if(temp[x] + temp[y] + temp[z] == 0){
                    result.push_back({temp[x], temp[y], temp[z]});
                    y++;
                    z--;
                } else if(temp[x] + temp[y] + temp[z] < 0){
                    y++;
                } else {
                    z--;
                }
            }
        }
        return result;
    }
};

int main(){
    Solution s;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = s.threeSum(nums);
    for(vector<int>& vec: result){
        cout << "[";
        for(int& num: vec){
            cout << num << " ";
        }
        cout << "]" << endl;
    }
    return 0;
}