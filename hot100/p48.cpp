#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
private:
    void rotateFourPos(vector<vector<int>>& matrix, int i, int j){
        // 四个点分别是(i, j), (j, n-i-1), (n-i-1, n-j-1), (n-j-1, i)
        int n = matrix.size();
        swap(matrix[i][j], matrix[j][n-i-1]);
        swap(matrix[i][j], matrix[n-i-1][n-j-1]);
        swap(matrix[i][j], matrix[n-j-1][i]);
    }
    // 奇数矩阵特有
    void rotateFourPos(vector<vector<int>>& matrix){
        // 旋转轴线上的点
        int n = matrix.size();
        int mid = (n - 1)/2;
        for(int i = 0; i < mid; i++){
            swap(matrix[i][mid], matrix[mid][n-i-1]);
            swap(matrix[i][mid], matrix[n-i-1][mid]);
            swap(matrix[i][mid], matrix[mid][i]);
        }
    }
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int mid = 0;
        if(n % 2 == 1){
            mid = (n - 1) / 2;
            rotateFourPos(matrix);
        } else {
            mid = n / 2;
        }
        for(int i = 0; i < mid; i++){
            for(int j = 0; j < mid; j++){
                rotateFourPos(matrix, i, j);
            }
        }
        return;
    }
};

int main(){
    Solution s;
    vector<vector<int>> matrix = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}, {16, 17, 18, 19, 20}, {21, 22, 23, 24, 25}};
    s.rotate(matrix);
    for(vector<int> v: matrix){
        for(int i: v){
            cout << i << " ";
        }
        cout << endl;
    }
}