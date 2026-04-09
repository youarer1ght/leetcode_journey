#include <vector>
#include <algorithm>
using namespace std;
class Solution {
private:
    int sum = 0;
    // 从正上开始，逆时针
    vector<vector<int>> dirs = {{-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}};
    bool inBound(int x, int y, int n, int m){
        return x >= 0 && x < n && y >= 0 && y < m;
    }
    void dfs(int x, int y, int n, int m, vector<vector<int>>& land){
        sum++;
        land[x][y] = 1;
        for(int dir = 0; dir < 8; dir++){
            int nx = x + dirs[dir][0];
            int ny = y + dirs[dir][1];
            if(inBound(nx, ny, n, m) && land[nx][ny] == 0){
                dfs(nx, ny, n, m, land);
            }
        }
    }
public:
    vector<int> pondSizes(vector<vector<int>>& land) {
        int n = land.size();
        int m = land[0].size();
        vector<int> result;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(land[i][j] == 0){
                    sum = 0;
                    dfs(i, j, n, m, land);
                    result.push_back(sum);
                }
            }
        }
        sort(result.begin(), result.end());
        return result;
    }
};