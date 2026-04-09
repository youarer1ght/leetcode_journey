#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
private:
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    bool inBound(int x, int y, int n, int m){
        return x >= 0 && x < n && y >= 0 && y < m;
    }
    int dfs(int x, int y, int n, int m, vector<string>& grid, vector<vector<bool>>& visited){
        int sum = 1;
        visited[x][y] = true;
        for(int dir = 0; dir < 4; dir++){
            int nx = x + dirs[dir][0];
            int ny = y + dirs[dir][1];
            if(inBound(nx, ny, n, m) && !visited[nx][ny] && grid[nx][ny] == grid[x][y]){
                sum += dfs(nx, ny, n, m, grid, visited);
            }
        }
        return sum;
    }
public:
    int largestArea(vector<string>& grid) {
        int n = grid.size();
        int m = grid[0].length();
        int maxArea = 0;
        // 可以用 6 代表 visited，节约空间
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        // 遍历圈边所有元素及内部零周围元素
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!visited[i][j]){
                    if(grid[i][j] == '0'){
                        visited[i][j] = true;
                        for(int dir = 0; dir < 4; dir++){
                            int x = i + dirs[dir][0];
                            int y = j + dirs[dir][1];
                            if(inBound(x, y, n, m) && grid[x][y] != '0'){
                                dfs(x, y, n, m, grid, visited);
                            }
                        }
                    } else if(i == 0 || i == n-1 || j == 0 || j == m-1){
                        dfs(i, j, n, m, grid, visited);
                    }
                }
            }
        }
        // 寻找内部空间
        for(int i = 1; i < n-1; i++){
            for(int j = 1; j < m-1; j++){
                if(!visited[i][j]){
                    int area = dfs(i, j, n, m, grid, visited);
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
};

int main(){
    Solution s;
    vector<string> grid = {"001", "001", "111"};
    int maxArea = s.largestArea(grid);
    cout << maxArea;
}