#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        int freshCount = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    freshCount++;
                } else if(grid[i][j] == 2){
                    q.push({i, j});
                }
            }
        }
        if(freshCount == 0){
            return 0;
        }
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int minutes = 0;
        // bfs
        while(!q.empty()){
            int size = q.size();
            bool rotted = false;    // 标记这一分钟是否有橘子腐烂
            for(int i = 0; i < size; i++){
                auto [x, y] = q.front();
                q.pop();
                for(auto& dir: dirs){
                    int nx = x + dir[0];
                    int ny = y + dir[1];
                    if(nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1){
                        grid[nx][ny] = 2;  // 腐烂
                        q.push({nx, ny});
                        freshCount--;
                        rotted = true;
                    }
                }
            }
            if(rotted){
                minutes++;
            }
        }
        return freshCount == 0 ? minutes : -1;
    }
};