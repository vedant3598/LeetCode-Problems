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
    TreeNode* ans = nullptr;
    
    void searchBSTUtil(TreeNode* root, const int &val){
        if(root == nullptr)
            return;
        
        if(root->val == val)
            ans = root;
        
        searchBSTUtil(root->left, val);
        searchBSTUtil(root->right, val);
        return;
    }
    
    TreeNode* searchBST(TreeNode* root, int val) {
        searchBSTUtil(root, val);
        return ans;
    }
};
