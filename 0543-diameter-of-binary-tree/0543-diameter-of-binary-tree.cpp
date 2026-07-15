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
    int height(TreeNode* root){
        if(root==NULL)return 0;
        return 1+max(height(root->left),height(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)return 0;
        int leftHeight=height(root->left);
        int rightHeight=height(root->right);

        int withRoot=leftHeight+rightHeight;
        int leftSubtree=diameterOfBinaryTree(root->left);
        int rightSubtree=diameterOfBinaryTree(root->right);
        return max({withRoot,leftSubtree,rightSubtree});
    }
};