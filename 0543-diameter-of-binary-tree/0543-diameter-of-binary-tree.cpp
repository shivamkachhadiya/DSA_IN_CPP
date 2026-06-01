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
    int solve(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        return 1+max(solve(root->left),solve(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)return 0;
        int left_h=solve(root->left);
        int right_h=solve(root->right);

        int leftSubtree_Recursive=diameterOfBinaryTree(root->left);
        int rightSubtree_Recurisve=diameterOfBinaryTree(root->right);
        
        return max({left_h+right_h,leftSubtree_Recursive,rightSubtree_Recurisve});
    }
};