class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0; // agar empty tree hai
        
        // agar left null hai to right ka depth lena hoga
        if (!root->left) return 1 + minDepth(root->right);
        // agar right null hai to left ka depth lena hoga
        if (!root->right) return 1 + minDepth(root->left);
        
        // dono child present hain
        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};
