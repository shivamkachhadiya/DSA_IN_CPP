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
    int maxSum=INT_MIN;

    int solve(TreeNode* root){
        if(root==NULL)return 0;
        int leftAns=solve(root->left);
        int rightAns=solve(root->right);

        int niche_hi_mil_gaya_ans=leftAns+rightAns+root->val;
        int koi_ek_achha=max(leftAns,rightAns)+root->val;
        int sirf_root_achha=root->val;

        maxSum=max({maxSum,niche_hi_mil_gaya_ans,koi_ek_achha,sirf_root_achha});
        return max(koi_ek_achha,sirf_root_achha);
    }
    int maxPathSum(TreeNode* root) {
         solve(root);
         return maxSum;
    }
};