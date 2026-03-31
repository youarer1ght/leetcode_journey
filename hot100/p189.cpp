#include <vector>
#include <iostream>
using namespace std;
/*
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 1){
            return;
        }
        k = k % n;
        reverse(nums, 0, n - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, n - 1);
    }
private:
    void reverse(vector<int>& nums, int left, int right){
        while(left < right){
            swap(nums[left], nums[right]);
            left++;
            right--;
        }
    }
};
*/
class Solution{
public:
    void rotate(vector)
private:
}
int main(){
    Solution s;
    vector<int> nums = {1, 2};
    int k = 7;
    s.rotate(nums, k);
    cout << "result :";
    for(int num: nums){
        cout << num << " ";
    }
    cout << endl;
}