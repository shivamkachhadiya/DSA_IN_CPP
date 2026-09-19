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
    int ans=INT_MIN;
    int solve(TreeNode* root) {
        if (root == NULL)
            return 0;
        
        int left=solve(root->left);
        int right=solve(root->right);

        int leftOnlyTakeWithReturn = root->val + left;
        int rightOnlyTakeWithReturn = root->val + right;
        int takeBothWithNoReturn =
            root->val + left +right;
        int takeOnlyRootWithReturn = root->val;
        int currSum = max({leftOnlyTakeWithReturn, rightOnlyTakeWithReturn,
                          takeBothWithNoReturn, takeOnlyRootWithReturn});
        ans=max(ans,currSum);
        return max({leftOnlyTakeWithReturn, rightOnlyTakeWithReturn,
                    takeOnlyRootWithReturn});
    }
    int maxPathSum(TreeNode* root) {
         solve(root);
        return ans;
    }
};