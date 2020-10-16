/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* inorderSuccessor(Node *node) {
        // If there's a right subtree then we can go right
        if (node->right) {
            node = node->right;
            while (node->left)
                node = node->left;
            return node;
        }
        
        // otherwise we have to look up somewhere
        while (node->parent && node == node->parent->right)
            node = node->parent;
        
        return node->parent;
    }
};
