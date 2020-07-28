/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root)
            return 0;

        auto lHeight = Height(root->left);
        auto rHeight = Height(root->right);

        int lDiameter = diameterOfBinaryTree(root->left);
        int rDiameter = diameterOfBinaryTree(root->right);

        return std::max(lHeight + rHeight, std::max(lDiameter, rDiameter));
    }

private:
    int Height(TreeNode *root) {
        if (!root)
            return 0;
        return 1 + std::max(Height(root->left), Height(root->right));
    }
};
