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
    void levelOrderUtil(vector<TreeNode*> parents){
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
            nodes.push_back(childrenNodes);
            levelOrderUtil(children);
        }
    }
    
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr){}
        else{
            vector<int> head;
            head.push_back(root->val);
            nodes.push_back(head);
            vector<TreeNode*> parents;
            parents.push_back(root);
            levelOrderUtil(parents);
        }
        return nodes;
    }
};
