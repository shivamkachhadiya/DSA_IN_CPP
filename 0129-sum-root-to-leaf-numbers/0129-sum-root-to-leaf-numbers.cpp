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
    vector<int>sum;
    void solve(TreeNode* root,int currsum){
        if(root==NULL)return;
        currsum=currsum*10+root->val;
        if(root->left==NULL&&root->right==NULL){
            sum.push_back(currsum);
            return;
        }
        solve(root->left,currsum);
        solve(root->right,currsum);
    }
    int sumNumbers(TreeNode* root) {
        solve(root,0);
        return accumulate(sum.begin(),sum.end(),0);
    }
};