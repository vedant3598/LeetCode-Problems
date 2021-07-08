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
    int preorderCount = 0;

    TreeNode* buildTreeUtil(const vector<int>& preorder, int l, int r){
        if(l > r)
            return nullptr;
                
        TreeNode* root = new TreeNode(preorder[preorderCount]);
        preorderCount++;
        
        root->left = buildTreeUtil(preorder, l, values[root->val] - 1);
        root->right = buildTreeUtil(preorder, values[root->val] + 1, r);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        for(int i = 0; i < inorder.size(); i++){
            values[inorder[i]] = i;
        }      
        
        return buildTreeUtil(preorder, 0, preorder.size() - 1);
    }
};
