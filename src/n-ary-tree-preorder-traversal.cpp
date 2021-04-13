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

class Solution {
public:
    vector<int> postOrderUtil(Node* root, vector<int> nodes){
        if(root == nullptr){
            return nodes;
        }
        
        for(int i = 0; i < root->children.size(); i++){
            nodes = postOrderUtil(root->children[i], nodes);
        }
        
        nodes.push_back(root->val);
        return nodes;
    }
    
    vector<int> postorder(Node* root) {
        vector<int> nodes;
        return postOrderUtil(root, nodes);
    }
};
