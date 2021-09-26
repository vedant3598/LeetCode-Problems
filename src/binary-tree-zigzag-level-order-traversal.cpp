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
    
    vector<vector<int>> ret;
    
    void zigzagLevelOrderUtil(vector<TreeNode*> parents, bool isZigZag){
        if(parents.size() == 0)
            return;
        
        vector<TreeNode*> children;
        vector<int> nums;
        if(isZigZag){
            for(int i = 0; i < parents.size(); i++){
                nums.push_back(parents[i]->val);
            }
            for(int i = parents.size() - 1; i >= 0; i--){
                if(parents[i]->right)
                    children.push_back(parents[i]->right);
                if(parents[i]->left)
                    children.push_back(parents[i]->left);
            }
            isZigZag = false;
        }
        else{
            for(int i = 0; i < parents.size(); i++){
                nums.push_back(parents[i]->val);
            }   
            for(int i = parents.size() - 1; i >= 0; i--){
                if(parents[i]->left)
                    children.push_back(parents[i]->left);
                if(parents[i]->right)
                    children.push_back(parents[i]->right);
            }
            isZigZag = true;
        }    
        ret.push_back(nums);
        zigzagLevelOrderUtil(children, isZigZag);
    }
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)
            return ret;
        
        bool isZigZag = true;
        vector<TreeNode*> temp;
        temp.push_back(root);
        zigzagLevelOrderUtil(temp, isZigZag);
        return ret;
    }
};
