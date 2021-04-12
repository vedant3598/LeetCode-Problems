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
    vector<int> preorderTraversalVector(TreeNode* root, vector<int> nodes){
        if(root == nullptr)
            return nodes;
        
        nodes.push_back(root->val);
        nodes = preorderTraversalVector(root->left, nodes);
        nodes = preorderTraversalVector(root->right, nodes);
        return nodes;
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> nodes;
        return preorderTraversalVector(root, nodes);
    }
};
