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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool sameTree = true;
        if(p != nullptr && q != nullptr){
            if(p->val == q->val){
                sameTree = true;
                sameTree = isSameTree(p->left,  q->left);
                if(!sameTree){
                    return sameTree;
                }
                else
                    sameTree = isSameTree(p->right,  q->right);
            }
            else{
                sameTree = false;
            }
        }
        else if(p != nullptr && q == nullptr || p == nullptr && q != nullptr){
            sameTree = false;
        }
        else{}
        return sameTree;
    }
};
