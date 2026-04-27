#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;    // num, i+1
        for(int i = 0; i < nums.size(); i++){
            if(cnt[nums[i]] > 0 && i + 1 - cnt[nums[i]] <= k){
                return true;
            } else {
                cnt[nums[i]] = i + 1;
            }
        }
        return false;
    }
};