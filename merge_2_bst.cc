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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        std::vector<int> p;
        std::vector<int> q;
        std::vector<int> v;

        InOrder(root1, p);
        InOrder(root2, q);

        if (q.empty())
            return p;
        else if
            (p.empty()) return q;
        else
            Merge(p, q, v);
        return v;
    }
private:
    void InOrder(TreeNode *root, std::vector<int> &v) {
        if (!root)
            return;

        if (root->left)
            InOrder(root->left, v);

        v.push_back(root->val);

        if (root->right)
            InOrder(root->right, v);
    }

    void Merge(const std::vector<int> p, const std::vector<int> q, std::vector<int> &v) {
        int i = 0, j = 0;

        while (i < p.size() || j < q.size()) {
            if (i == p.size() || j == q.size())
                break;
            if (p[i] <= q[j])
                v.push_back(p[i++]);
            else
                v.push_back(q[j++]);
        }

        if (i < p.size())
            while (i < p.size())
                v.push_back(p[i++]);
        else
            while (j < q.size())
                v.push_back(q[j++]);
    }
};
