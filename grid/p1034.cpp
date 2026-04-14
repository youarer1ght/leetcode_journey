#include <vector>
#include <queue>
using namespace std;
class Solution {
    vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    bool inBound(int x, int y, int n, int m){
        return x >= 0 && x < n && y >= 0 && y < m;
    }
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int n = grid.size();
        int m = grid[0].size();
        int target = grid[row][col];
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        vector<vector<int>> result = grid;
        q.push({row, col});
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            if(x == 0 || x == n-1 || y == 0 || y == m-1){
                result[x][y] = color;
            }
            visited[x][y] = true;
            q.pop();
            for(int dir = 0; dir < 4; dir++){
                int nx = x + dirs[dir].first;
                int ny = y + dirs[dir].second;
                if(!inBound(nx, ny, n, m) || visited[nx][ny]){
                    continue;
                }
                if(result[x][y] != color && grid[nx][ny] != target){
                    result[x][y] = color;
                }
                if(grid[nx][ny] == target){
                    q.push({nx, ny});
                }
            }
        }
        return result;
    }
};