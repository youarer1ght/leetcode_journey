#include <vector>
#include <tuple>
using namespace std;
class Solution {
private:
    // {x, y, z}
    vector<tuple<int, int, int>> dirs = {{0, 0, 1}, {0, 0, -1}, {0, 1, 0}, {0, -1, 0}, {1, 0, 0}, {-1, 0, 0}};
    bool inBound(int x, int y, int z, int n, int m, vector<vector<int>>& grid){
        return x >= 0 && x < n && y >= 0 && y < m && z >= 0 && z < grid[x][y];
    }
    int around(int x, int y, int z, int n, int m, vector<vector<int>>& grid){
        int plain = 0;
        for(int dir = 0; dir < 6; dir++){
            int nx = x + get<0>(dirs[dir]);
            int ny = y + get<1>(dirs[dir]);
            int nz = z + get<2>(dirs[dir]);
            if(!inBound(nx, ny, nz, n, m, grid)){
                plain++;
            }
        }
        return plain;
    }
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                for(int k = 0; k < grid[i][j]; k++){
                    count += around(i, j, k, n, m, grid);
                }
            }
        }
        return count;
    }
};