#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return {};
        }

        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> result;
        result.reserve(m * n);

        int top = 0, bottom = m - 1, left = 0, right = n - 1;

        while (top <= bottom && left <= right) {
            // 向右：从左到右遍历上边界
            for (int j = left; j <= right; ++j) {
                result.push_back(matrix[top][j]);
            }
            top++; // 上边界下移

            // 向下：从上到下遍历右边界
            for (int i = top; i <= bottom; ++i) {
                result.push_back(matrix[i][right]);
            }
            right--; // 右边界左移

            // 向左：从右到左遍历下边界（如果还有下边界）
            if (top <= bottom) {
                for (int j = right; j >= left; --j) {
                    result.push_back(matrix[bottom][j]);
                }
                bottom--; // 下边界上移
            }

            // 向上：从下到上遍历左边界（如果还有左边界）
            if (left <= right) {
                for (int i = bottom; i >= top; --i) {
                    result.push_back(matrix[i][left]);
                }
                left++; // 左边界右移
            }
        }

        return result;
    }
};

int main() {
    Solution s;
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> result = s.spiralOrder(matrix);

    cout << "[";
    for (size_t i = 0; i < result.size(); ++i) {
        cout << result[i];
        if (i < result.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}