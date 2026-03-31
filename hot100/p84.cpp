#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;  // 存储下标
        int maxArea = 0;
        
        for (int i = 0; i <= n; i++) {
            // 当 i == n 时，curHeight = 0，确保所有柱子出栈
            int curHeight = (i == n) ? 0 : heights[i];
            
            while (!st.empty() && curHeight < heights[st.top()]) {
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }
        
        return maxArea;
    }
};