#include <iostream>

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
    int maxDiameter = 0;
    int depth(TreeNode* root){
        if(!root){
            return 0;
        }
        int leftMax = depth(root->left);
        int rightMax = depth(root->right);
        maxDiameter = max(maxDiameter, leftMax + rightMax);
        return 1 + max(leftMax, rightMax);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);
        return maxDiameter;
    }
};