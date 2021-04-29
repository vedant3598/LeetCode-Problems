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
    bool isSubtreeUtil2(TreeNode* s, TreeNode* t){
        if(s == nullptr && t == nullptr)
            return true;
        else if(s != nullptr && t == nullptr)
                return false;
        else if(s == nullptr && t != nullptr)
            return false;
        else {}
        
        return (s->val == t->val) && isSubtreeUtil2(s->left, t->left) && isSubtreeUtil2(s->right, t->right);
    }
    
    bool isSubtreeUtil1(TreeNode* s, TreeNode* t){
        return s != nullptr && (isSubtreeUtil2(s, t) || isSubtreeUtil1(s->left, t) || isSubtreeUtil1(s->right, t));
    }
    
    
    bool isSubtree(TreeNode* s, TreeNode* t) {
        return isSubtreeUtil1(s, t);
    }
};
