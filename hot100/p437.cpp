#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    // 前缀和、哈希表
    int dfs(TreeNode* node, long long currSum, int target, unordered_map<long long, int>& prefixSumCount){
        if(!node){
            return 0;
        }
        // 更新当前路径和
        currSum += node->val;
        // 查看有多少条路径满足 currSum - prefixSum = target
        int count = prefixSumCount[currSum - target];
        // 当前前缀和加如哈希表
        prefixSumCount[currSum]++;
        // 递归处理左右子树
        count += dfs(node->left, currSum, target, prefixSumCount);
        count += dfs(node->right, currSum, target, prefixSumCount);
        // 回溯
        prefixSumCount[currSum]--;
        return count;
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> prefixSumCount;
        prefixSumCount[0] = 1;
        return dfs(root, 0, targetSum, prefixSumCount); 
    }
};