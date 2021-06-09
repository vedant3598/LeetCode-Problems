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
    void invertTreeUtil(TreeNode* &left, TreeNode* &right){
        if(left == nullptr && right == nullptr)
            return;
        else if(left != nullptr && right != nullptr){
            int temp = left->val;
            left->val = right->val;
            right->val = temp;
            invertTreeUtil(left->left, right->right);   
            invertTreeUtil(left->right, right->left);   
        }
        else if(left != nullptr && right == nullptr){
            right = new TreeNode(left->val, left->left, left->right);
            invertTreeUtil(right->left, right->right);   
            left = nullptr;
        }
        else if(left == nullptr && right != nullptr){
            left = new TreeNode(right->val, right->left, right->right);
            invertTreeUtil(left->left, left->right);   
            right = nullptr;  
        }
        return;
    }
    
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr)
            return root;
        
        invertTreeUtil(root->left, root->right);
        return root;
    }
};
