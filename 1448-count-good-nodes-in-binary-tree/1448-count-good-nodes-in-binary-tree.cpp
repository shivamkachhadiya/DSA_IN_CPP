/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int golbal_ans = 0;
    void solve(TreeNode* root, int k) {
        if (root == NULL) {
            return;
        }
        if (root->left==NULL&&root->right==NULL&&root->val >= k) {
            golbal_ans++;
            return;
        }

        if(root->val>=k){
            golbal_ans++;
        }
        int newMax=max(k,root->val);
        solve(root->left, newMax);
        solve(root->right,newMax);
    }
    int goodNodes(TreeNode* root) { 
        if(root==NULL)return 0;
        solve(root, root->val); 
        return golbal_ans;
     }
};