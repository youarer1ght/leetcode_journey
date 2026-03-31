#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));

        for (int i = 0; i < n; i++){
            board[0][i] = 'Q';  // 在第一行放置皇后
            backtrace(result, board, 1);    // 从第二行开始放置皇后
            board[0][i] = '.';  // 回溯，撤销第一行的皇后
        }
        return result;
    }
private:
    void backtrace(vector<vector<string>>& result, vector<string>& board, int row){
        if (row == board.size()){
            result.push_back(board);    // 找到一个合法的解，保存到结果中
            return;
        }
        for (int col = 0; col < board.size(); col++){
            if (IsValid(board, row, col)){
                board[row][col] = 'Q';
                backtrace(result, board, row + 1);
                board[row][col] = '.';
            }
        }
    }

    bool IsValid(const vector<string>& board, int row, int col){
        for (int i = 0; i < row; i++){
            // 检查同列
            if (board[i][col] == 'Q')
                return false;

            // 检查左上对角线：需要边界检查
            int left = col - (row - i);
            if (left >= 0 && board[i][left] == 'Q')
                return false;

            // 检查右上对角线：需要边界检查
            int right = col + (row - i);
            if (right < board.size() && board[i][right] == 'Q')
                return false;
        }
        return true;
    }
};

int main(){
    Solution s;
    vector<vector<string>> result = s.solveNQueens(4);
    cout << "Number of solutions: " << result.size() << endl;
    return 0;
}