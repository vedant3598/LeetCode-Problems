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
    int left = 0;
    
    void findBottomLeftValueUtil(vector<TreeNode*> &parent){
        if(parent.size() == 0)
            return;
        
        for(int i = 0; i < 1; i++){
            left = parent[i]->val;
        }
        
        vector<TreeNode*> children;
        for(int i = 0; i < parent.size(); i++){
            if(parent[i]->left != nullptr)
                children.push_back(parent[i]->left);
            if(parent[i]->right != nullptr)
                children.push_back(parent[i]->right);
        }
        
        findBottomLeftValueUtil(children);
        return;
    }
    
    
    int findBottomLeftValue(TreeNode* root) {
        vector<TreeNode*> parent;
        parent.push_back(root);
        findBottomLeftValueUtil(parent);
        return left;
    }
};
