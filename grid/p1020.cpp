#include <vector>
#include <queue>
using namespace std;
class Solution {
private:
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    bool inBound(int x, int y, int n, int m){
        return x >= 0 && x < n && y >= 0 && y < m;
    }
    void dfs(int x, int y, int n, int m, vector<vector<int>>& grid){
        if(grid[x][y] == 0){
            return;
        }
        grid[x][y] = 0;
        for(int dir = 0; dir < 4; dir++){
            int nx = x + dirs[dir][0];
            int ny = y + dirs[dir][1];
            if(inBound(nx, ny, n, m) && grid[nx][ny] == 1){
                dfs(nx, ny, n, m, grid);
            }
        }
        return;
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i < n; i++){
            dfs(i, 0, n, m, grid);
            dfs(i, m-1, n, m, grid);
        }
        for(int j = 0; j < m; j++){
            dfs(0, j, n, m, grid);
            dfs(n-1, j, n, m, grid);
        }
        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                count += grid[i][j];
            }
        }
        return count;
    }
};