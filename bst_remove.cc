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
    TreeNode* deleteNode(TreeNode* root, int key) {
        deleteNodeRecur(root, key);
        return root;
    }

private:
    TreeNode* Min(TreeNode* root) {
        if (!root) return nullptr;
        while (root->left)
            root = root->left;
        return root;
    }

    void deleteNodeRecur(TreeNode *&root, int key) {
        if (!root)
            return;

        if (key < root->val)
            deleteNodeRecur(root->left, key);

        else if (key > root->val)
            deleteNodeRecur(root->right, key);

        else {
            if (root->left && !root->right)
                root = root->left;

            else if (!root->left && root->right)
                root = root->right;

            else if (root->left && root->right) {
                // Two children so get the minimum of the right subtree
                TreeNode *min_rst = Min(root->right);
                root->val = min_rst->val;
                // delete that node because it's already been promoted
                deleteNodeRecur(root->right, root->val);
            }

            else
                // Leaf node
                root = nullptr;
        }
    }
};
