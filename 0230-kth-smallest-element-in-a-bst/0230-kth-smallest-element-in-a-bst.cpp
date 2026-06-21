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
    int count = 0;
    int ans=0;
    void solve(TreeNode* root,int k){
        if(root==NULL)return;
        //in order
        solve(root->left,k);
        count++;
        if(count==k){
            ans=root->val;
            return;
        }
        solve(root->right,k);
     
    }
    int kthSmallest(TreeNode* root, int k) {
        if(root==NULL)return 0;
        solve(root,k);
        return ans;
    }
};