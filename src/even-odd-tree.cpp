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
    bool isEvenOddTreeUtil(vector<TreeNode*>& parents, int &level){
        if(parents.size() == 0)
            return true;
        
        int currVal = parents[0]->val;
        if(level % 2 == 0){
            if(currVal % 2 != 0){
                for(int i = 1; i < parents.size(); i++){
                    if(!(currVal % 2 != 0 && parents[i]->val % 2 != 0 && parents[i]->val > currVal))
                        return false;
                    currVal = parents[i]->val;
                 }   
            }
            else
                return false;
        }
        if(level % 2 != 0){
            if(currVal % 2 == 0){
                for(int i = 1; i < parents.size(); i++){
                    if(!(currVal % 2 == 0 && parents[i]->val % 2 == 0 && parents[i]->val < currVal))
                        return false;
                    currVal = parents[i]->val;
                }
            }
            else
                return false;
        }
        
        vector<TreeNode*> children;
        for(int i = 0; i < parents.size(); i++){
            if(parents[i]->left != nullptr)
                children.push_back(parents[i]->left);
            if(parents[i]->right != nullptr)
                children.push_back(parents[i]->right);
        }
        
        return isEvenOddTreeUtil(children, ++level);
    }
    
    bool isEvenOddTree(TreeNode* root) {
        vector<TreeNode*> parent;
        int level = 0;
        parent.push_back(root);
        return isEvenOddTreeUtil(parent, level);
    }
};
