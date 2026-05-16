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
        return 1+max(height(root->right),height(root->left));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)return 0;
        int left_height=height(root->left);
        int right_height=height(root->right);
        int leftRecursive=diameterOfBinaryTree(root->left);
        int rightRecursive=diameterOfBinaryTree(root->right);
        return max({left_height+right_height,leftRecursive,rightRecursive});
    }
};