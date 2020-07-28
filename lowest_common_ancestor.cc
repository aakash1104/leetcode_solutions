/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root)
            return nullptr;
        if (root->val == p->val || root->val == q->val)
            return root;

        auto lca_left = lowestCommonAncestor(root->left, p, q);
        auto lca_right = lowestCommonAncestor(root->right, p, q);

        if (lca_left && lca_right)
            // If key exists in two different subtrees, then this node is the LCA
            return root;

        return lca_left ? lca_left : lca_right;
    }
};
