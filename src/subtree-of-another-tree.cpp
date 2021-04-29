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
    bool isSubtreeUtil(TreeNode* s, TreeNode* t){
        if(s == nullptr && t == nullptr)
            return true;
        else if(s != nullptr && t == nullptr)
                return false;
        else if(s == nullptr && t != nullptr)
            return false;
        else {}
        
        bool left = false;
        bool right = false;
        
        if(s->val == t->val && ((s->left != nullptr && t->left == nullptr) || (s->right != nullptr && t->right == nullptr))){
            left = isSubtreeUtil(s->left, t);
            if(left)
                return true;
            right = isSubtreeUtil(s->right, t);
        }
        else if(s->val == t->val){
            if(s->left != nullptr && t->left != nullptr){
                if(s->left->val == t->left->val)
                    left = isSubtreeUtil(s->left, t->left);
            }
            else
                left = isSubtreeUtil(s->left, t->left);
            if(s->right != nullptr && t->right != nullptr){
                if(s->right->val == t->right->val)
                    right = isSubtreeUtil(s->right, t->right);
            }
            else
                right = isSubtreeUtil(s->right, t->right);
        }
        else{
            left = isSubtreeUtil(s->left, t);
            if(left)
                return true;
            right = isSubtreeUtil(s->right, t);
        }
        return left && right;
    }
    
    bool isSubtree(TreeNode* s, TreeNode* t) {
        return isSubtreeUtil(s, t);
    }
};
