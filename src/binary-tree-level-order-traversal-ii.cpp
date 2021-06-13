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
    vector<vector<int>> nodes;
    
    void levelOrderBottomUtil(vector<TreeNode*> parent){
        if(parent.size() == 0)
            return;
        
        vector<int> nums;
        vector<TreeNode*> children;
        for(int i = 0; i < parent.size(); i++){
            nums.push_back(parent[i]->val);
            if(parent[i]->left != nullptr)
                children.push_back(parent[i]->left);
            if(parent[i]->right != nullptr)
                children.push_back(parent[i]->right);
        }
        levelOrderBottomUtil(children);
        
        nodes.push_back(nums);
        return;
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root == nullptr)
            return nodes;
        vector<TreeNode*> parent;
        parent.push_back(root);
        levelOrderBottomUtil(parent);
        return nodes;
    }
};
