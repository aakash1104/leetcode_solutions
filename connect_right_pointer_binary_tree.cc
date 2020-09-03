/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root)
            return nullptr;
        ConnectRecur(root->left, root->right);
        return root;
    }
private:
    void ConnectRecur(Node* &lt, Node* &rt) {
        if (!lt || !rt)
            return;
        lt->next = rt;
        
        ConnectRecur(lt->left, lt->right);
        ConnectRecur(lt->right, rt->left);
        ConnectRecur(rt->left, rt->right);
    }
};
