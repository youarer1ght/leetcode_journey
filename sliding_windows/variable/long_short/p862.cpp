#include <vector>
#include <iostream>
#include <deque>
using namespace std;

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k){
        int n = nums.size();
        vector<long> preSum(n+1, 0);
        for(int i = 0; i < n; i++){
            preSum[i + 1] = preSum[i] + nums[i];
        }
        int minLen = n + 1;
        deque<int> dq;
        for (int i = 0; i <= n; i++) {
            // 1. 检查队首：如果满足条件，记录答案并弹出（它不会再成为更优解）
            while (!dq.empty() && preSum[i] - preSum[dq.front()] >= k) {
                minLen = min(minLen, i - dq.front());
                dq.pop_front();
            }
            // 2. 维护单调性：弹出队尾中前缀和 ≥ 当前值的索引（保留更小的，更容易满足条件）
            while (!dq.empty() && preSum[dq.back()] >= preSum[i]) {
                dq.pop_back();
            }
            // 3. 当前索引入队
            dq.push_back(i);
        }
        return minLen > n ? -1 : minLen;
    }
};

/* 前缀和
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {  
        int n = nums.size();
        vector<int> preSum(n + 1, 0);
        for(int i = 0; i < n; i++){
            preSum[i+1] = preSum[i] + nums[i];
        }
        for(int L = 1; L <= n; L++){
            for(int i = 0; i <= n - L; i++){
                if(preSum[i+L] - preSum[i] >= k){
                    return L;
                }
            }
        }
        return -1;
    }
};
*/
int main(){
    vector<int> nums = {2, -1, 2};
    int k = 3;
    Solution s;
    cout << s.shortestSubarray(nums, k);
}