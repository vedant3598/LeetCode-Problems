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
    map<int, int> values;
    int postorderCount;
    
    TreeNode* buildTreeUtil(const vector<int>& postorder, int l, int r){
        if(l > r)
            return nullptr;
        
        TreeNode* root = new TreeNode(postorder[postorderCount]);
        postorderCount--;
        
        root->right = buildTreeUtil(postorder, values[root->val] + 1, r);
        root->left = buildTreeUtil(postorder, l, values[root->val] - 1);        
        
        return root;
    }
    
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        postorderCount = postorder.size() - 1;
        for(int i = 0; i < inorder.size(); i++){
            values[inorder[i]] = i;
        }
        return buildTreeUtil(postorder, 0, postorder.size() - 1);
    }
};
