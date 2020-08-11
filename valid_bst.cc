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
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        
        std::vector<int> v;
        InOrderTraversal(root, v);
        
        for (int i = 0; i < v.size() - 1; i++)
            if (v.at(i) >= v.at(i + 1))
                return false;
        
        return true;
    }
private:
    void InOrderTraversal(TreeNode *root, std::vector<int> &v) {
        if (!root) return;
        
        InOrderTraversal(root->left, v);
        
        v.push_back(root->val);
        
        InOrderTraversal(root->right, v);
    }
};
