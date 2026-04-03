#include <vector>
using namespace std;
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> result(n, -1);
        if(nums.size() < 2 * k + 1){
            return result;
        }
        long long sum = 0;
        for(int i = 0; i < 2 * k + 1; i++){
            sum += nums[i];
        }
        result[k] = sum / (2 * k + 1);
        for(int i = 2 * k + 1; i < nums.size(); i++){
            sum = sum - nums[i - 2 * k - 1] + nums[i];
            result[i - k] = sum / (2 * k + 1);
        }
        return result;
    }
};