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
    int diameter = 0;
    int dfs(TreeNode* root) {
        if (root == NULL)
            return 0;
        int left_h = dfs(root->left);
        int right_h = dfs(root->right);
        diameter = max(diameter, left_h + right_h);
        return 1 + max(left_h, right_h);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return diameter;
    }
};