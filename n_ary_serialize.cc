/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(Node* root) {
        if (!root) return "";
        string res = "";
        queue<Node*> q;
        q.push(root);
        res += std::to_string(root->val) + ",null";
        
        while (!q.empty()) {
            int s = q.size();
            for (int i = 0; i < s; i++) {
                auto node = q.front();
                q.pop();
                for (auto child : node->children) {
                    res += "," + std::to_string(child->val);
                    q.push(child);
                }
                res += ",null";
            }
        }
        
        return res;
    }
	
    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        cout << data << endl;
        if (data.empty()) return nullptr;
        
        vector<string> nodes;
        stringstream ss(data);
        string token;
        
        while (std::getline(ss, token, ','))
            nodes.push_back(token);
        
        Node *root = new Node(std::stoi(nodes[0]));
        vector<Node *> tree;
        tree.push_back(root);
        int pos1 = 0, pos2 = 2;
        
        while (pos2 < nodes.size()) {
            vector<Node *> children_in_this_level;
            while (nodes[pos2] != "null") {
                Node *n = new Node(std::stoi(nodes[pos2++]));
                children_in_this_level.push_back(n);
                tree.push_back(n);
            }
            tree[pos1++]->children =  children_in_this_level;
            ++pos2; // Because after loop we reached null so increment for next value
        }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
