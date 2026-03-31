#include <vector>
#include <deque>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;  // 存储索引，维护有序数组
        vector<int> result;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            if(!dq.empty() && dq.front() <= i - k){
                dq.pop_front();
            }
            while(!dq.empty() && nums[dq.back()] < nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            if(i >= k - 1){
                result.push_back(nums[dq.front()]);
            }
        }
        return result;
    }
};

int main(){
    Solution s;
    vector<int> nums = {9,10,9,-7,-4,-8,2,-6};
    int k = 5;
    vector<int> result = s.maxSlidingWindow(nums, k);
    for(int num: result){
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
