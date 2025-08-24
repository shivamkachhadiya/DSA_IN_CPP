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
    void inorder(TreeNode* root,vector<int>& data){
        if(root==NULL){
            return;
        }
        inorder(root->left,data);
        data.push_back(root->val);
        inorder(root->right,data);
    }
    bool findTarget(TreeNode* root, int k) {

        vector<int>data;
        inorder(root,data);
        int n=data.size();
        int start=0;
        int end=n-1;
        while(start<end){
            int sum=data[start]+data[end];
            if(sum==k)return true;
            if(sum>k)end--;
            if(sum<k)start++;
        }
        return false;
        
    }
};