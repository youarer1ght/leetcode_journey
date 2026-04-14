#include <vector>
#include <queue>
#include <tuple>
using namespace std;
class Solution {
private:
    int dirs[3][2] = {{-1, 1}, {1, 1}, {0, 1}};
    bool inBound(int x, int y, int n, int m){
        return x >= 0 && x < n && y >= 0 && y < m;
    }
    int maxCount(int x, int y, int n, int m, vector<vector<int>>& grid){
        queue<tuple<int, int, int>> q;
        q.push({x, y, 0});
        int maxCount = 0;
        while(!q.empty()){
            int cx = get<0>(q.front());
            int cy = get<1>(q.front());
            int count = get<2>(q.front());
            maxCount = max(maxCount, count);
            q.pop();
            for(int dir = 0; dir < 3; dir++){
                int nx = cx + dirs[dir][0];
                int ny = cy + dirs[dir][1];
                if(inBound(nx, ny, n, m) && grid[nx][ny] > grid[cx][cy]){
                    q.push({nx, ny, count+1});
                }
            }
        }
        return maxCount;
    }
public:
    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxStep = 0;
        for(int i = 0; i < n; i++){
            maxStep = max(maxStep, maxCount(i, 0, n, m, grid));
        }
        return maxStep;
    }
};