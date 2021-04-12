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
    vector<int> postorderTraversalVector(TreeNode* root, vector<int> nodes){
        if(root == nullptr)
            return nodes;
        
        nodes = postorderTraversalVector(root->left, nodes);
        nodes = postorderTraversalVector(root->right, nodes);
        nodes.push_back(root->val);
        return nodes;
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> nodes;
        return postorderTraversalVector(root, nodes);
    }
};
