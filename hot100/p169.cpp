#include <vector>
#include <unordered_map>
using namespace std;
class Solution {public:
    int majorityElement(vector<int>& nums) {
        int count = 0, candidate = 0;
        for(int num: nums){
            if(count == 0){
                candidate = num;
            }
            count += (num == candidate) ? 1 : -1;
        }
        return candidate;
    }
};
/*
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq;
        for(int i: nums){
            freq[i] += 1;
        }
        for(auto p: freq){
            if(p.second > n/2){
                return p.first;
            }
        }
        return 0;
    }
};
*/