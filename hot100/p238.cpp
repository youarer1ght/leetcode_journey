#include <vector>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> preProduct(n, 1);
        vector<int> postProduct(n, 1);
        for(int i = 0; i < n - 1; i++){
            preProduct[i + 1] = preProduct[i] * nums[i];
        }
        for(int i = n - 1; i > 0; i--){
            postProduct[i - 1] = postProduct[i] * nums[i];
        }
        vector<int> result;
        for(int i = 0; i < n; i++){
            result.push_back(preProduct[i] * postProduct[i]);
        }
        return result;
    }
};