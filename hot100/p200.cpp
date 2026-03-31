#include <vector>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int m = grid.size();       // 行数
        int n = grid[0].size();    // 列数
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                    count++;
                    Spread(grid, m, n, i, j);
                }
            }
        }
        return count;
    }
private:
    void Spread(vector<vector<char>>& grid, const int m, const int n, int i, int j){
        // 越界检查或已被访问，直接返回
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != '1'){
            return;
        }
        grid[i][j] = '0';  // 标记为已访问（沉岛）
        Spread(grid, m, n, i-1, j);  // 上
        Spread(grid, m, n, i+1, j);  // 下
        Spread(grid, m, n, i, j-1);  // 左
        Spread(grid, m, n, i, j+1);  // 右
    }
};