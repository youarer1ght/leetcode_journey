#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixCount;  // 前缀和 -> 出现次数
        prefixCount[0] = 1;  // 初始化：前缀和为0出现1次
        int prefixSum = 0;
        int count = 0;

        for(int i = 0; i < nums.size(); i++){
            prefixSum += nums[i];
            // 查找之前有多少个前缀和等于 prefixSum - k
            if(prefixCount.find(prefixSum - k) != prefixCount.end()){
                count += prefixCount[prefixSum - k];
            }
            // 记录当前前缀和
            prefixCount[prefixSum]++;
        }
        return count;
    }
};

int main(){
    Solution solution;
    vector<int> nums = {6, 4, 3, 1};
    int k = 10;
    int result = solution.subarraySum(nums, k);
    cout << result << endl;
    return 0;
}