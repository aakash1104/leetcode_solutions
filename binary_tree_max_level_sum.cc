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
    int maxLevelSum(TreeNode* root) {
        std::queue<TreeNode*> q;

        int curr_level = 1, max_level = 1;
        int curr_sum = 0, max_sum = root->val;
        
        TreeNode *marker = nullptr;
        
        q.push(root);
        q.push(marker);
            
        while (q.size() > 1) {
            auto node = q.front();
            q.pop();
            
            if (node != marker) {
                curr_sum += node->val;
                
                if (node->left)
                    q.push(node->left);
                
                if (node->right)
                    q.push(node->right);
                
            } else {
                // Go to next level
                if (curr_sum > max_sum) {
                    max_sum = curr_sum;
                    max_level = curr_level;
                }
                
                curr_sum = 0;
                curr_level++;
                q.push(marker);
            }
        }
        
        // Check last level
        if (curr_sum > max_sum) {
            max_sum = curr_sum;
            max_level = curr_level;
        }
        
        return max_level;
    }
};
