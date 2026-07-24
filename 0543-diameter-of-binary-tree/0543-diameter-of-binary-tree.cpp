
class Solution {
public:
    int height(TreeNode* root){
        if(root==NULL)return 0;
        return 1+max(height(root->left),height(root->right));
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)return 0;
        int left_H=height(root->left);
        int right_H=height(root->right);
        int left_sub_tree=diameterOfBinaryTree(root->left);
        int right_sub_tree=diameterOfBinaryTree(root->right);
        return max({left_H+right_H,left_sub_tree,right_sub_tree});
    }
};