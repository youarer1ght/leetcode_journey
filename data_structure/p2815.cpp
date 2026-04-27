#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_map<int, int> digit;  // maxDigit, maxNum
        int maxSum = -1;
        for(int i = 0; i < nums.size(); i++){
            int d = 0;
            int num = nums[i];
            while(num){
                d = max(d, num % 10);
                num /= 10;
            }
            if(digit[d] > 0){
                maxSum = max(maxSum, digit[d] + nums[i]);
            }
            digit[d] = max(digit[d], nums[i]);
        }
        return maxSum;
    }
};