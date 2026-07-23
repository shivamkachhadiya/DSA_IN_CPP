/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL)return NULL;
        if(root->val==p->val||root->val==q->val)return root;
        TreeNode* left_rec=lowestCommonAncestor(root->left,p,q);
        TreeNode* right_rec=lowestCommonAncestor(root->right,p,q);
        if(left_rec&&right_rec)return root;
        if(!left_rec&&right_rec)return right_rec;
        if(left_rec&&!right_rec)return left_rec;
        return NULL;
    }
};