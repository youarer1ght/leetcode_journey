#include <vector>
#include <unordered_set>
#include <cmath>
using namespace std;
class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int ans = -1;
        unordered_set<int> s;
        for(int x: nums){
            if(s.count(-x)){
                ans = max(ans, abs(x));
            }
            s.insert(x);
        }
        return ans;
    }
};