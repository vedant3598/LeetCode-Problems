/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    
    void serializeUtil(string &ser, TreeNode* root){
        if(root == nullptr)
            return;
        
        serializeUtil(ser, root->left);
        ser = ser + to_string(root->val);
        serializeUtil(ser, root->right);
        return;
    }
    

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ser = "";
        serializeUtil(ser, root);
        return ser;
    }
    
    TreeNode* deserializeUtil(int &count, const string& data){
        if(data == "")
            return nullptr;
        
        TreeNode* root = new TreeNode(0);
        
        root->left = deserializeUtil(count, data);
        root->val = (data[count++]);
        root->right = deserializeUtil(count, data);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int count = 0;
        return deserializeUtil(count, data);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
