#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if(nums.size() == 1){
            return nums[0];
        }
        priority_queue<int> q;
        for(int i = 0; i < nums.size(); i++){
            q.push(nums[i]);
        }
        for(int i = 0; i < k - 1; i++){
            q.pop();
        }
        return q.top();
    }
};