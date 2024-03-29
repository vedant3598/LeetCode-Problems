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
class Solution1 {
public:
    map<int, int> findModeUtil(TreeNode* root, map<int, int> dict, int &highestVal){
        if(root == nullptr)
            return dict;
        
        if(dict.find(root->val) == dict.end()){
            dict[root->val] = 1;
        }
        else{
            dict[root->val]++;
        }
        
        if(dict[root->val] > highestVal){
            highestVal = dict[root->val];
        }
        
        dict = findModeUtil(root->left, dict, highestVal);
        dict = findModeUtil(root->right, dict, highestVal);
        
        return dict;
    }

    vector<int> findMode(TreeNode* root) {
        vector<int> ret;
        map<int, int> dict;
        int highestVal = 0;
        dict = findModeUtil(root, dict, highestVal);
        
        for(map<int, int>::iterator it = dict.begin(); it != dict.end(); it++){
            if(it->second == highestVal)
                ret.push_back(it->first);
        }
        return ret;
    }
};


class Solution2 {
public:
    map<int, int> dict;
    vector<int> ret;
    int highestVal = 0;
    void findModeUtil(TreeNode* root){
        if(root == nullptr)
            return;
        
        dict[root->val]++;
        highestVal = max(highestVal, dict[root->val]);
        findModeUtil(root->left);
        findModeUtil(root->right);
    }

    vector<int> findMode(TreeNode* root) {
        findModeUtil(root);
        
        for(auto it : dict){
            if(it.second == highestVal)
                ret.push_back(it.first);
        }
        return ret;
    }
};
