#include <vector>
#include <algorithm>
using namespace std;
class Solution {
private:
    // 上0 下1 左2 右3
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    bool inBound(int x, int y, int n, int m){
        return x >= 0 && x < n && y >= 0 && y < m;
    }
    int dfs(int x, int y, int n, int m, vector<vector<int>>& grid){
        int sum = grid[x][y];
        grid[x][y] = 0;
        for(int dir = 0; dir < 4; dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(inBound(nx, ny, n, m) && grid[nx][ny] > 0){
                sum += dfs(nx, ny, n, m, grid);
            }
        }
        return sum;
    }
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxSum = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] > 0){
                    maxSum = max(maxSum, dfs(i, j, n, m, grid));
                }
            }
        }
        return maxSum;
    }
};