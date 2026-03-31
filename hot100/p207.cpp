#include <queue>
#include <vector>
using namespace std;
// bfs
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);    // 邻接表
        vector<int> indegree(numCourses, 0);    // 入度
        for(auto& pre: prerequisites){
            int a = pre[0]; // 依赖课程
            int b = pre[1]; // 先修课程
            adj[b].push_back(a);    // b->a
            indegree[a]++;  // a的入度+1
        }
        // 将所有入度为0的课程入队
        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        int count = 0;  // 已学习的课程数
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            count++;
            for(int next: adj[curr]){
                indegree[next]--;
                if(indegree[next] == 0){
                    q.push(next);
                }
            }
        }
        return count == numCourses;
    }
};