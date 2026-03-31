#include <string>
#include <vector>
using namespace std;

class Solution {
private:
    int m, n;
    bool findWord;
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    bool backtrack(vector<vector<char>>& board, string word, int i, int j, int index){
        if(index == word.size()){
            return true;
        }
        if(i < 0 || i >= m || j < 0 || j >= n){
            return false;
        }
        if(board[i][j] != word[index]){
            return false;
        }
        char temp = board[i][j];
        board[i][j] = '0';
        for(auto& dir: dirs){
            if(backtrack(board, word, i + dir[0], j + dir[1], index + 1)){
                board[i][j] = temp;
                return true;
            }
        }
        board[i][j] = temp;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(backtrack(board, word, i, j, 0)){
                    return true;
                }
            }
        }
        return false;
    }
};