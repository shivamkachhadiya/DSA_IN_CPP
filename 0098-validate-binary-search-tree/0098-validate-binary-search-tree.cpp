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
    void inorder(TreeNode* root,vector<int>&data){
        if(root==NULL)return;
        
        inorder(root->left,data);
        data.push_back(root->val);
        inorder(root->right,data);
        
    }
    bool isValidBST(TreeNode* root) {
        if(root==NULL)return true;
        vector<int>data;
        inorder(root,data);
        for(int i=1;i<data.size();i++){
            if(data[i]<=data[i-1]){
                return false;
            }
        }
        return true;
    }
};