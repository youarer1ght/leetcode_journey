#include <vector>
using namespace std;
class Solution {
private:
    // 左0 右1 上2 下3
    vector<int> dx = {0, 0, -1, 1};
    vector<int> dy = {-1, 1, 0, 0};
    bool inBound(int x, int y, int n, int m){
        return x >= 0 && x < n && y >= 0 && y < m;
    }
    void spread(int x, int y, int n, int m, vector<vector<char>>& grid){
        if(grid[x][y] == 0){
            return;
        }
        grid[x][y] = '0';
        for(int dir = 0; dir < 4; dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(inBound(nx, ny, n, m) && grid[nx][ny] == '1'){
                spread(nx, ny, n, m, grid);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1'){
                    spread(i, j, n, m, grid);
                    count++;
                }
            }
        }
        return count;
    }
};