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
    int sum = 0;
    
    void sumNumbersUtil(TreeNode* root, string num){        
        num += to_string(root->val);
        
        if(root->left == nullptr && root->right == nullptr){
            sum += stoi(num);
            return;
        }
        
        if(root->left != nullptr)
            sumNumbersUtil(root->left, num);
        if(root->right != nullptr)
            sumNumbersUtil(root->right, num);
        return;
    }
    
    int sumNumbers(TreeNode* root) {
        string num = "";
        sumNumbersUtil(root, num);
        return sum;
    }
};
