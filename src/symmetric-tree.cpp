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
    
    bool isSymmetricUtil(vector<TreeNode*> &parent){
        bool symmetric = true;
        
        int val = 0;
        for(int i = 0; i < parent.size(); i++){
            if(parent[i] == nullptr)
                val++;
        }
        if(val == parent.size())
            return symmetric;
        
        vector<TreeNode*> children;
        for(int i = 0; i < parent.size(); i++){
            if(parent[i] == nullptr)
                children.push_back(nullptr);
            else{
                children.push_back(parent[i]->left);
                children.push_back(parent[i]->right);
            }
        }
        
        if(children.size() % 2 == 0){
            int p1 = 0;
            int p2 = children.size() - 1;
            while(p1 <= p2){
                if(children[p1] != nullptr && children[p2] != nullptr){
                    if(children[p1]->val != children[p2]->val){
                        symmetric = false;
                        break;
                    }
                }
                else{
                    if(!(children[p1] == nullptr && children[p2] == nullptr)){
                        symmetric = false;
                        break;
                    }
                }
                p1++;
                p2--;
            }
        }
        else
            return false;
        
        return symmetric && isSymmetricUtil(children);
    }
    
    
    bool isSymmetric(TreeNode* root) {
        vector<TreeNode*> parent;
        parent.push_back(root);
        return isSymmetricUtil(parent);
    }
};
