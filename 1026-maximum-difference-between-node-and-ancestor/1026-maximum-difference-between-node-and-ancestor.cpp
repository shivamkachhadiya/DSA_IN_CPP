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
    // int max_diff = 0;
    // void solve(TreeNode* root, TreeNode* fixRoot) {
    //     if (root == NULL)
    //         return;
    //     int diff = abs(fixRoot->val - root->val);
    //     max_diff = max(max_diff, diff);
    //     solve(root->left, fixRoot);
    //     solve(root->right, fixRoot);
    // }
    int solve(TreeNode*root,int maxVal,int minVal){
        if(root==NULL)return maxVal-minVal;
        int maxi=max(root->val,maxVal);
        int mini=min(root->val,minVal);
        int leftAns=solve(root->left,maxi,mini);
        int rightAns=solve(root->right,maxi,mini);
        return max(leftAns,rightAns);
    }
    int maxAncestorDiff(TreeNode* root) {
        if (root == NULL)
            return 0;
        // solve(root->left, root);
        // solve(root->right, root);

        // maxAncestorDiff(root->left);
        // maxAncestorDiff(root->right);

        // return max_diff;
        return solve(root,root->val,root->val);

    }
};