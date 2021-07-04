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
    vector<double> average;
    void averageOfLevelsUtil(vector<TreeNode*> parent){
        if(!parent.size())
            return;
        
        vector<TreeNode*> children;
        double sum  = 0;
        for(int i = 0; i < parent.size(); i++){
            sum += parent[i]->val;
            if(parent[i]->left)
                children.push_back(parent[i]->left);
            if(parent[i]->right)
                children.push_back(parent[i]->right);
        }
        average.push_back(sum/parent.size());
        averageOfLevelsUtil(children);
        return;
    }
    
    vector<double> averageOfLevels(TreeNode* root) {
        vector<TreeNode*> parent;
        parent.push_back(root);
        averageOfLevelsUtil(parent);
        return average;
    }
};
