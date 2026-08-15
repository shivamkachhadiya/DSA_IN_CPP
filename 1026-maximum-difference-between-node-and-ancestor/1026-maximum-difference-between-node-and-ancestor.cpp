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
    int max_diff=0;
    void solve(TreeNode* root,TreeNode* fixRoot){
        if(root==NULL)return;
        int diff=abs(fixRoot->val-root->val);
        max_diff=max(max_diff,diff);
        solve(root->left,fixRoot);
        solve(root->right,fixRoot);
    }
    int maxAncestorDiff(TreeNode* root) {
                if (root == NULL) return 0;
        solve(root->left,root);
        solve(root->right,root);

       maxAncestorDiff(root->left);
       maxAncestorDiff(root->right);

        return max_diff;

    }
};