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
    bool hasPathSumUtil(TreeNode* root, const int &targetSum, int &sum){
        if(root == nullptr)
            return false;
        
        sum += root->val;
        
        if(root->left == nullptr && root->right == nullptr && sum == targetSum)
            return true;
        
        int temp = sum;
        return hasPathSumUtil(root->left, targetSum, sum) || hasPathSumUtil(root->right, targetSum, temp);
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;    
        return hasPathSumUtil(root, targetSum, sum);     
    }
};
