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
    vector<int> inorderTraversalVector(TreeNode* root, vector<int> nodes){
        if(root == nullptr)
            return nodes;
        
        nodes = inorderTraversalVector(root->left, nodes);
        nodes.push_back(root->val);
        nodes = inorderTraversalVector(root->right, nodes);
        return nodes;
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> nodes;
        return inorderTraversalVector(root, nodes);
    }
};
