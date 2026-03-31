class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }

private:
    int dfs(TreeNode* node, int currentSum) {
        if (!node) return 0;
        
        currentSum = currentSum * 10 + node->val;
        
        if (!node->left && !node->right) {
            return currentSum;
        }
        
        return dfs(node->left, currentSum) + dfs(node->right, currentSum);
    }
};