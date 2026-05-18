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
    void solve(TreeNode* root,vector<int>&temp){
        if(root==NULL)return;
        temp.push_back(root->val);
        solve(root->left,temp);
        solve(root->right,temp);
    }
    void flatten(TreeNode* root) {
        if(root == NULL) return;   // add this

        vector<int>temp;
        solve(root,temp);
        TreeNode* newRoot=root;
        for(int i=1;i<temp.size();i++){
            newRoot->left=NULL;
            newRoot->right=new TreeNode(temp[i]);
            newRoot=newRoot->right;
        }
    }
};