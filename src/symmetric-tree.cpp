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
    bool isSymmetricUtil(vector<TreeNode*> parent){
        vector<TreeNode*> children;
        for(int i = 0; i < parent.size(); i++){
            children.push_back(parent[i]->left);
            children.push_back(parent[i]->right);
        }
    }
    
    bool isSymmetric(TreeNode* root) {
        vector<TreeNode*> parent;
        parent.push_back(root);
        return isSymmemtricUtil(parent);
    }
};
