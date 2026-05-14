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
    vector<int>solve(TreeNode* root,vector<int>&result,int level){
        if(!root)return result;
        if(level==result.size()){
            result.push_back(root->val);
        }
        solve(root->right,result,level+1);
        solve(root->left,result,level+1);
        return result;
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>result;
        return solve(root,result,0);
    }
};