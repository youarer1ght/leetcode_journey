#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 中序遍历
class Solution {
private:
    vector<int> result;
    void inorder(TreeNode* root, vector<int>& result, int k){
        if(!root){
            return;
        }
        inorder(root->left, result, k);
        result.push_back(root->val);
        inorder(root->right, result, k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        inorder(root, result, k);
        return result[k-1];
    }
};