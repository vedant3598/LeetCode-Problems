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
    int longestPath = 0;
    
    int longestUnivaluePathUtil(TreeNode* root){
        if(root == nullptr)
            return 0;
        
        int left = longestUnivaluePathUtil(root->left);
        int right = longestUnivaluePathUtil(root->right);
        
        int leftCount = 0;
        int rightCount = 0;
        
        if(root->left != nullptr && root->val == root->left->val)
            leftCount = left + 1;
        if(root->right != nullptr && root->val == root->right->val)
            rightCount = right + 1;
        
        longestPath = max(longestPath, leftCount + rightCount);
        return max(leftCount, rightCount);
    }
    
    int longestUnivaluePath(TreeNode* root) {
        int num = longestUnivaluePathUtil(root);
        return longestPath;
    }
};
