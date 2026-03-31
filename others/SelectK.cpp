#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    
    void backtracking(int n, int k, int startIndex) {
        // 终止条件：找到 k 个数的组合
        if (path.size() == k) {
            result.push_back(path);
            return;
        }
        
        // 剪枝优化：搜索起点的上界 = n - (k - path.size()) + 1
        for (int i = startIndex; i <= n - (k - path.size()) + 1; i++) {
            path.push_back(i);           // 处理节点
            backtracking(n, k, i + 1);   // 递归
            path.pop_back();              // 回溯，撤销处理结果
        }
    }
    
public:
    vector<vector<int>> combine(int n, int k) {
        result.clear();
        path.clear();
        backtracking(n, k, 1);
        return result;
    }
};

// 打印结果
void printCombinations(const vector<vector<int>>& combinations) {
    cout << "所有组合（共 " << combinations.size() << " 种）：" << endl;
    for (const auto& comb : combinations) {
        cout << "[";
        for (size_t i = 0; i < comb.size(); i++) {
            cout << comb[i];
            if (i < comb.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
}

int main() {
    int n = 5, k = 3;
    
    Solution sol;
    vector<vector<int>> combinations = sol.combine(n, k);
    
    printCombinations(combinations);
    
    return 0;
}