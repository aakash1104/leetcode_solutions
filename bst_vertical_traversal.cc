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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        std::queue<Pair> q;
        std::vector<std::vector<int>> v;
        std::unordered_map<int, std::vector<int>> ht;
        
        int min_col = 0, max_col = 0;
        
        if (!root) return v;
        
        q.push(std::make_pair(root, 0));
        while (!q.empty()) {
            auto info = q.front();
            q.pop();

            min_col = std::min(info.second, min_col);
            max_col = std::max(info.second, max_col);
            
            if (ht.find(info.second) == ht.end()) {
                std::vector<int> c;
                c.push_back(info.first->val);
                ht.emplace(info.second, c);
            } else {
                ht.find(info.second)->second.push_back(info.first->val);
            }
            
            if (info.first->left)
                q.push(std::make_pair(info.first->left, info.second - 1));
            
            if (info.first->right)
                q.push(std::make_pair(info.first->right, info.second + 1));
        }

        for (int col = min_col; col <= max_col; col++)
            v.push_back(ht.find(col)->second);
        
        return v;  
    }
};
