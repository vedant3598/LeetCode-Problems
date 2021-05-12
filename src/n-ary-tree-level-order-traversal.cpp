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
    vector<vector<int>> nodes;
    
    void levelOrderUtil(vector<Node*> parentNodes){
        vector<int> node;
        vector<Node*> childrenNodes;
        for(int i = 0; i < parentNodes.size(); i++){
            for(int x = 0; x < parentNodes[i]->children.size(); x++){
                //cout << parentNodes[i]->children[x]->val << endl;
                node.push_back(parentNodes[i]->children[x]->val);
                childrenNodes.push_back(parentNodes[i]->children[x]);
            }
        }
        if(node.size() != 0){
            nodes.push_back(node);
            levelOrderUtil(childrenNodes);
        }
        return;  
    }
    
    
    vector<vector<int>> levelOrder(Node* root) {
        if(root == nullptr)
            return nodes;
        
        vector<int> head;
        head.push_back(root->val);
        nodes.push_back(head);
        vector<Node*> parentNode;
        parentNode.push_back(root);
        levelOrderUtil(parentNode);
        return nodes;
    }
};
