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

    void _serialize(TreeNode* root,string &s){
        if(!root){
            s+="#,";
            return;
        }
        s+=to_string(root->val)+",";
        _serialize(root->left,s);
        _serialize(root->right,s);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        _serialize(root,s);
        return s;
    }

    TreeNode* _deserialize(queue<string>&tokens){
        string val=tokens.front();
        tokens.pop();
        if(val=="#"){
            return NULL;
        }
        TreeNode* root=new TreeNode(stoi(val));
        root->left=_deserialize(tokens);
        root->right=_deserialize(tokens);
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string>tokens;
        string cur;
        for(char c:data){
            if(c==','){
                tokens.push(cur);
                cur="";
            }else{
                cur+=c;
            }
        }
        if(!cur.empty())tokens.push(cur);
        return _deserialize(tokens);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));