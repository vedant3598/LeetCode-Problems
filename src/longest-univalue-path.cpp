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
    int longestPath = 0;
    
    int longestUnivaluePathUtil(TreeNode* root, int currNum, int currPath){
        if(root == nullptr)
            return 0;
        
        //cout << root->val << " " << currNum << endl;
        if(root->val == currNum)
            currPath++;
        else{
            currNum = root->val;
            currPath = 0;
        }
        int path = longestUnivaluePathUtil(root->left, root->val, currPath) + longestUnivaluePathUtil(root->right, root->val, currPath);

        if(path > longestPath)
            longestPath = path;
        
        return currPath;
    }
    
    
    int longestUnivaluePath(TreeNode* root) {
        int currNum = INT_MAX;
        int currPath = 0;
        int num = longestUnivaluePathUtil(root, currNum, currPath);
        return longestPath;
    }
};
