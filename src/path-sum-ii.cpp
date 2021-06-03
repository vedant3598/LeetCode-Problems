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
    vector<vector<int>> paths;
    
    void pathSumUtil(TreeNode* root, int curr, const int targetSum, vector<int> currNums){
        if(root == nullptr)
            return;
        
        if(root->left == nullptr && root->right == nullptr){
            curr += root->val;
            if(curr == targetSum){
                currNums.push_back(root->val);
                paths.push_back(currNums);
            }
        }
        else{
            curr += root->val;
            currNums.push_back(root->val);
            pathSumUtil(root->left, curr, targetSum, currNums);
            pathSumUtil(root->right, curr, targetSum, currNums);
        }
        return;
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int curr = 0;
        vector<int> currNums;
        pathSumUtil(root, curr, targetSum, currNums);
        return paths;
    }
};
