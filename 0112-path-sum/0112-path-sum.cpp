class Solution {
public:
    bool inOrder(TreeNode* root, int tar, int sum) {
        if (root == NULL)
            return false;

        sum += root->val;  // pehle root->val add karo

        // agar leaf node hai aur sum match karta hai
        if (root->left == NULL && root->right == NULL && sum == tar)
            return true;

        // left/right recursion ka result return karo
        return inOrder(root->left, tar, sum) || inOrder(root->right, tar, sum);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        return inOrder(root, targetSum, 0);
    }
};
