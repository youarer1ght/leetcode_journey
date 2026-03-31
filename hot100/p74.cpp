#include <vector>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == target){
                    return true;
                }
                if(i + 1 < m && matrix[i+1][j] > target){
                    m = i + 2;
                }
                if(j + 1 < n && matrix[i][j+1] > target){
                    n = j + 2;
                }
            }
        }
        return false;
    }
};