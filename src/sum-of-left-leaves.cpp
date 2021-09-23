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
    int sum = 0;
    void sumOfLeftLeavesUtil(TreeNode* root){
        if(root == nullptr)
            return;
        
        if(root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr)
            sum += root->left->val;
        
        sumOfLeftLeavesUtil(root->left);
        sumOfLeftLeavesUtil(root->right);
        return;
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        bool isLeft = false;
        sumOfLeftLeavesUtil(root);
        return sum;
    }
};
