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
    int min = 0;
    
    void minDepthUtil(TreeNode* root, int curr){
        if(root->left == nullptr && root->right == nullptr){
            curr++;
            if(curr < min && min != 0)
                min = curr;
            else if(min == 0)
                min = curr;
            return;
        }
        
        curr++;
        if(root->left != nullptr)
            minDepthUtil(root->left, curr);
        if(root->right != nullptr)
            minDepthUtil(root->right, curr);
            
        return;
    }
    
    int minDepth(TreeNode* root) {
        int curr = 0;
        if(root == nullptr)
            return min;
        minDepthUtil(root, curr);
        return min;
    }
};
