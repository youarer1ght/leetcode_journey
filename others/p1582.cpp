#include <vector>
using namespace std;
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int count = 0;
        for(int i = 0; i < mat.size(); ++i){
            for(int j = 0; j < mat[0].size(); ++j){
                if(IsSpecial(mat, i, j)){
                    count++;
                }
            }
        }
        return count;
    }
private:
    bool IsSpecial(const vector<vector<int>>& mat, int row, int col){
        if(mat[row][col] != 1){
            return false;
        }
        for(int i = 0; i < mat.size(); ++i){
            if(i != row && mat[i][col] == 1){
                return false;
            }
        }
        for(int j = 0; j < mat[0].size(); ++j){
            if(j != col && mat[row][j] == 1){
                return false;
            }
        }
        return true;
    }
};