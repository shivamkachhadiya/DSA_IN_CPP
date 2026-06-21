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
        TreeNode* left_search=lowestCommonAncestor(root->left,p,q);
        TreeNode* right_search=lowestCommonAncestor(root->right,p,q);
        if(left_search&&right_search)return root;
        if(!left_search&&right_search)return right_search;
        if(left_search&&!right_search)return left_search;
        return NULL;
    }
};