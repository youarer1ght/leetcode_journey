#include <vector>
#include <queue>
using namespace std;
class Solution {
private:
    // 上0 下1 左2 右3
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    bool inBound(int x, int y, int n, int m){
        return x >= 0 && x < n && y >= 0 && y < m;
    }
    long long dfs(int x, int y, int n, int m, vector<vector<int>>& grid){
        long long cost = grid[x][y];
        grid[x][y] = 0;
        for(int dir = 0; dir < 4; dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(inBound(nx, ny, n, m) && grid[nx][ny] > 0){
                cost += dfs(nx, ny, n, m, grid);
            }
        }
        return cost;
    }
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] > 0){
                    count += !(dfs(i, j, n, m, grid) % k);
                }
            }
        }
        return count;
    }
};

/*bfs
class Solution {
private:
    // 上0 下1 左2 右3
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    bool inBound(int x, int y, int n, int m){
        return x >= 0 && x < n && y >= 0 && y < m;
    }
    bool bfs(int x, int y, int n, int m, vector<vector<int>>& grid, vector<vector<bool>>& visited, int k){
        long long cost = 0;
        queue<pair<int, int>> q;
        q.push({x, y});
        visited[x][y] = true;
        while(!q.empty()){
            int cx = q.front().first;
            int cy = q.front().second;
            cost += grid[cx][cy];
            q.pop();
            for(int dir = 0; dir < 4; dir++){
                int nx = cx + dx[dir];
                int ny = cy + dy[dir];
                if(inBound(nx, ny, n, m) && grid[nx][ny] > 0 && visited[nx][ny] == false){
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }
        }
        return !(cost % k);
    }
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] > 0 && !visited[i][j]){
                    if(bfs(i, j, n, m, grid, visited, k)){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};
*/