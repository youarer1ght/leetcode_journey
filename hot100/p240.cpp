#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // 从右上角开始收缩
        int m = matrix.size();
        int n = matrix[0].size();
        int i = 0;
        int j = n - 1;
        while(i < m && j >= 0){
            if(matrix[i][j] == target){
                return true;
            } else if(matrix[i][j] > target){
                j--;
            } else {
                i++;
            }
        }
        return false;
    }
};

int main(){
    Solution s;
    vector<vector<int>> matrix = {{-1, 3}};
    bool result = s.searchMatrix(matrix, 3);
    cout << (result ? "True" : "False") << endl;
}