#include <vector>
#include <queue>
using namespace std;
class Solution {
private:
    // 左0 右1 上2 下3
    vector<int> dx = {0, 0, -1, 1};
    vector<int> dy = {-1, 1, 0, 0};
    bool inBound(int x, int y, int n, int m){
        return x >= 0 && x < n && y >= 0 && y < m;
    }
    int bfs(int x, int y, int n, int m, vector<vector<int>>& grid, vector<vector<bool>>& visited){
        visited[x][y] = true;
        int area = 1;
        queue<pair<int, int>> q;
        q.push({x, y});
        while(!q.empty()){
            int cx = q.front().first;
            int cy = q.front().second;
            q.pop();
            for(int dir = 0; dir < 4; dir++){
                int nx = cx + dx[dir];
                int ny = cy + dy[dir];
                if(inBound(nx, ny, n, m) && grid[nx][ny] == 1 && !visited[nx][ny]){
                    visited[nx][ny] = true;
                    area++;
                    q.push({nx, ny});
                }
            }
        }
        return area;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxArea = 0;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1 && visited[i][j] == false){
                    int currArea = bfs(i, j, n, m, grid, visited);
                    maxArea = max(maxArea, currArea);
                }
            }
        }
        return maxArea;
    }
};