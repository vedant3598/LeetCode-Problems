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
    map<int, char> dict;
    string s = "";
    int smallest = INT_MAX;
    
    void mapping(){
        char c = 97;
        for(int i = 0; i < 26; i++){
            dict[i] = c;
            c++;
        }
    }
    
    string reverse(string rev){
        string ret = "";
        for(int i = rev.length() - 1; i >= 0; i--){
            ret += rev[i];
        }
        return ret;
    }
    
    void util(TreeNode* root, string curr){
        if(root == nullptr)
            return;
        
        curr += dict[root->val];
        
        if(root->left == nullptr && root->right == nullptr){
            string rev = reverse(curr);
            if((s != "" && rev < s) || s == "")
                s = rev;
        }
        else{
            util(root->left, curr);
            util(root->right, curr);
        }
        
        return;
    }
    
    string smallestFromLeaf(TreeNode* root) {
        mapping();
        string curr = "";
        util(root, curr);
        return s;
    }
};
