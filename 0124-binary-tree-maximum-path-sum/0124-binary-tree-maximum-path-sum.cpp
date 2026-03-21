class Solution {
public:
    int maxSum = INT_MIN;

    int helper(TreeNode* root) {
        if (!root) return 0;

        int left = max(0, helper(root->left));
        int right = max(0, helper(root->right));

        // Path passing through current node
        int currentPath = root->val + left + right;

        maxSum = max(maxSum, currentPath);

        // Return max gain to parent
        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        helper(root);
        return maxSum;
    }
};