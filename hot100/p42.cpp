#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> leftMax(height.size(), 0);
        vector<int> rightMax(height.size(), 0);
        for(int i = 1; i < height.size(); i++){
            leftMax[i] = max(leftMax[i-1], height[i-1]);
        }
        for(int i = height.size() - 2; i >= 0; i--){
            rightMax[i] = max(rightMax[i+1], height[i+1]);
        }
        int result = 0;
        for(int i = 0; i < height.size(); i++){
            int minHeight = min(leftMax[i], rightMax[i]);
            if(minHeight > height[i]){
                result += minHeight - height[i];
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    int result = s.trap(height);
    cout << result << endl;  // 输出结果
    return 0;
}