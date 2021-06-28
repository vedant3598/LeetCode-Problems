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
    vector<int> nodes;
    
    void largestValuesUtil(vector<TreeNode*> parents){
        if(parents.size() == 0)
            return;
        
        vector<int> childrenNodes;
        vector<TreeNode*> children;
        
        for(int i = 0; i < parents.size(); i++){
            if(parents[i]->left != nullptr){
                childrenNodes.push_back(parents[i]->left->val);
                children.push_back(parents[i]->left);
            }
            if(parents[i]->right != nullptr){
                childrenNodes.push_back(parents[i]->right->val);
                children.push_back(parents[i]->right);
            }
        }
        
        if(childrenNodes.size() != 0){
            int max = childrenNodes[0];
            for(int i = 1; i < childrenNodes.size(); i++){
                if(childrenNodes[i] > max)
                    max = childrenNodes[i];
            }
            nodes.push_back(max);
            largestValuesUtil(children);
        }
    }

    vector<int> largestValues(TreeNode* root) {
        if(root == nullptr){}
        else{
            nodes.push_back(root->val);
            vector<TreeNode*> parents;
            parents.push_back(root);
            largestValuesUtil(parents);
        }
        return nodes;
    }
};
