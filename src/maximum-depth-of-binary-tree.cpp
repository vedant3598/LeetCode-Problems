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
    int currMax = 0;
    
    void maxDepthUtil(TreeNode* root, int curr){
        if(root == nullptr){
            if(curr > currMax)
                currMax = curr;
            return;
        }
        curr++;
        maxDepthUtil(root->left, curr);
        maxDepthUtil(root->right, curr);
        return;
    }
    
    int maxDepth(TreeNode* root) {
        int curr = 0;
        maxDepthUtil(root, curr);
        return currMax;
    }
};
