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
    vector<int> getLonelyNodes(TreeNode* root) {
        vector<int> v;
        DFS(root, v);
        return v;
    }
    
private:
    void DFS(TreeNode *root, vector<int> &v) {
        if (!root)
            return;
        if (root->left && !root->right)
            v.push_back(root->left->val);
        if (!root->left && root->right)
            v.push_back(root->right->val);
        DFS(root->left, v);
        DFS(root->right, v);
    }
};
