#include <vector>
using namespace std;
class Solution {
private:
    vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    bool inBound(int x, int y, int n, int m){
        return x >= 0 && x < n && y >= 0 && y < m;
    }
    int around(int x, int y, int n, int m, vector<vector<int>>& grid){
        int edge = 0;
        for(int dir = 0; dir < 4; dir++){
            int nx = x + dirs[dir].first;
            int ny = y + dirs[dir].second;
            if(!inBound(nx, ny, n, m)){
                edge++;
            } else if(grid[nx][ny] == 0){
                edge++;
            }
        }
        return edge;
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    count += around(i, j, n, m, grid);
                }
            }
        }   
        return count;
    }
};