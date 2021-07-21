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
    void getKSmall(TreeNode* &root, int &element, int &kSmall, int k){
        if(root == nullptr){
            return;
        }
        getKSmall(root->left, element, kSmall, k);
        kSmall++;
        if(kSmall == k){
            element = root->val;
        }
        getKSmall(root->right, element, kSmall, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        int kSmall = 0;
        int element = root->val;
        getKSmall(root, element, kSmall, k);
        return element;
    }
};
