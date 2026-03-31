#include <vector>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int target = 0;
        for(int i = 0, j = height.size() - 1; i < j;){
            int area = min(height[i], height[j]) * (j - i);
            target = max(target, area);
            if(height[i] < height[j]){
                i++;
            } else {
                j--;
            }
        }
        return target;
    }
};