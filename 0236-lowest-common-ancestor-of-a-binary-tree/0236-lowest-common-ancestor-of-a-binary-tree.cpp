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
        TreeNode* left_ans=lowestCommonAncestor(root->left,p,q);
        TreeNode* right_ans=lowestCommonAncestor(root->right,p,q);
        if(left_ans&&right_ans)return root;
        if(!left_ans&&right_ans)return right_ans;
        if(left_ans&&!right_ans)return left_ans;
        return NULL;
    }
};