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
typedef std::pair<TreeNode*, int> Pair;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root)
            return {};

        std::vector<std::vector<int>> bfs;
        std::vector<int> l;
        std::queue<Pair> q;
        int level = 0;

        q.push(std::make_pair(root, level));
        while (!q.empty()) {
            auto info = q.front();
            if (level != info.second) {
                bfs.push_back(l);
                l.clear();
                level++;
            }
            l.push_back(info.first->val);
            q.pop();
            if (info.first->left)
                q.push(std::make_pair(info.first->left, info.second + 1));
            if (info.first->right)
                q.push(std::make_pair(info.first->right, info.second + 1));

        }
        bfs.push_back(l);
        return bfs;
    }
};
