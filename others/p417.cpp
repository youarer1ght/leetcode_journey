#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> result;
        if(heights.empty() || heights[0].empty()) return result;

        int m = heights.size();    // 行数
        int n = heights[0].size(); // 列数

        // 标记数组：表示该位置是否能流入对应海洋
        vector<vector<bool>> canReachPacific(m, vector<bool>(n, false));
        vector<vector<bool>> canReachAtlantic(m, vector<bool>(n, false));

        // 从太平洋边界（第一行和第一列）开始DFS
        for(int j = 0; j < n; j++) {
            dfs(heights, 0, j, heights[0][j], canReachPacific);
        }
        for(int i = 0; i < m; i++) {
            dfs(heights, i, 0, heights[i][0], canReachPacific);
        }

        // 从大西洋边界（最后一行和最后一列）开始DFS
        for(int j = 0; j < n; j++) {
            dfs(heights, m - 1, j, heights[m - 1][j], canReachAtlantic);
        }
        for(int i = 0; i < m; i++) {
            dfs(heights, i, n - 1, heights[i][n - 1], canReachAtlantic);
        }

        // 取交集：同时能流入两个海洋的位置
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(canReachPacific[i][j] && canReachAtlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }

private:
    void dfs(vector<vector<int>>& heights, int i, int j, int prevHeight,
             vector<vector<bool>>& canReach) {
        int m = heights.size();
        int n = heights[0].size();

        // 边界检查
        if(i < 0 || i >= m || j < 0 || j >= n) return;

        // 已访问或当前高度小于prevHeight（无法流入），直接返回
        if(canReach[i][j] || heights[i][j] < prevHeight) return;

        // 标记该位置可达
        canReach[i][j] = true;

        // 向四个方向递归
        dfs(heights, i + 1, j, heights[i][j], canReach); // 下
        dfs(heights, i - 1, j, heights[i][j], canReach); // 上
        dfs(heights, i, j + 1, heights[i][j], canReach); // 右
        dfs(heights, i, j - 1, heights[i][j], canReach); // 左
    }
};
