#include <vector>
#include <queue>
#include <tuple>
using namespace std;
class Solution {
private:
    vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    bool inBound(int x, int y, int n, int m){
        return x >= 0 && x < n && y >= 0 && y < m;
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int target = image[sr][sc];
        vector<vector<int>> result = image;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<pair<int, int>> q;
        q.push({sr, sc});
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            result[x][y] = color;
            visited[x][y] = true;
            for(int dir = 0; dir < 4; dir++){
                int nx = x + dirs[dir].first;
                int ny = y + dirs[dir].second;
                if(inBound(nx, ny, n, m) && !visited[nx][ny] && image[nx][ny] == target){
                    q.push({nx, ny});
                }
            }
        }
        return result;
    }
};