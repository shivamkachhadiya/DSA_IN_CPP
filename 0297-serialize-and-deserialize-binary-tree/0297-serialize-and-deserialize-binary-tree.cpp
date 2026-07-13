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

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL)return "";
        queue<TreeNode*>q;
        string ans="";
        q.push(root);

        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();

            if(curr==NULL){
                ans+="#,";
            }else{
                ans+=to_string(curr->val)+',';
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="")return NULL;
        string temp="";
        vector<string>tokens;
        for(auto &ch:data){
            if(ch==','){
                tokens.push_back(temp);
                temp="";
            }else{
                temp+=ch;
            }
        }

        TreeNode* root=new TreeNode(stoi(tokens[0]));
        queue<TreeNode*>q;
        q.push(root);
        int i=1;

        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            if(tokens[i]!="#"){
                curr->left=new TreeNode(stoi(tokens[i]));
                q.push(curr->left);
            }
            i++;
            if(tokens[i]!="#"){
                curr->right=new TreeNode(stoi(tokens[i]));
                q.push(curr->right);
            }
            i++;

        }

        return root;

    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));