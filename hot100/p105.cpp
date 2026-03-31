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

class Solution {
private:
    TreeNode* build(vector<int>& preorder, int preStart, int preEnd,
                   vector<int>& inorder, int inStart, int inEnd) {
        if (preStart > preEnd){
            return nullptr;
        }
        // 在 inorder 找到根节点 preorder[preStart]
        TreeNode* root = new TreeNode(preorder[preStart]);
        int leftIndex = inStart;
        while(inorder[leftIndex] != preorder[preStart]){
            leftIndex++;
        }
        int leftSize = leftIndex - inStart;
        // 分别构建左右子树
        root->left = build(preorder, preStart + 1, preStart + leftSize, inorder, inStart, inStart + leftSize - 1);
        root->right = build(preorder, preStart + leftSize + 1, preEnd, inorder, inStart + leftSize + 1, inEnd);
        return root;
    }
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, 0, preorder.size() - 1,
                    inorder, 0, inorder.size() - 1);
    }
};