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
    vector<string> paths;
    
    void binaryTreePathsUtil(TreeNode* root, string curr){
        if(root == nullptr)
            return;
        
        if(root->left == nullptr && root->right == nullptr){
            curr += to_string(root->val);
            paths.push_back(curr);
        }
        else{
            curr += to_string(root->val);
            curr += "->";
            binaryTreePathsUtil(root->left, curr);
            binaryTreePathsUtil(root->right, curr);
        }
        return;
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        string curr = "";
        binaryTreePathsUtil(root, curr);
        return paths;
    }
};
