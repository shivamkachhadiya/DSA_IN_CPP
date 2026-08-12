#include <climits>

class Solution {
public:
    bool solve(TreeNode* root, long long minVal, long long maxVal) {
        if (root == NULL) return true;
        if (root->val <= minVal || root->val >= maxVal) return false;
        return solve(root->left, minVal, root->val) &&
               solve(root->right, root->val, maxVal);
    }

    bool isValidBST(TreeNode* root) {
        return solve(root, LLONG_MIN, LLONG_MAX);
    }
};
