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
    int count = 0;
    
    void pathSumUtil(TreeNode* root, const int &targetSum, vector<int> &curr){
        if(root == nullptr)
            return;
        
        cout << root->val << endl;
        
        for(int i = 0; i < curr.size(); i++){
            curr[i] += root->val;
            if(curr[i] == targetSum){
                count++;
            }
        }
        curr.push_back(root->val);
        if(curr[curr.size() - 1] == targetSum)
            count++;
        
        vector<int> right = curr;
        pathSumUtil(root->left, targetSum, curr);
        pathSumUtil(root->right, targetSum, right);
        return;
    }
    
    
    int pathSum(TreeNode* root, int targetSum) {
        vector<int> curr;
        pathSumUtil(root, targetSum, curr);
        return count;
    }
};
