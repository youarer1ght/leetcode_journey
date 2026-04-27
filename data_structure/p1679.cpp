#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> freq;   // num, freq
        int n = nums.size();
        int count = 0;
        for(int i = 0; i < n; i++){
            if(freq[k-nums[i]] > 0){
                count++;
                freq[k-nums[i]]--;
            } else {
                freq[nums[i]]++;
            }
        }
        return count;
    }
};