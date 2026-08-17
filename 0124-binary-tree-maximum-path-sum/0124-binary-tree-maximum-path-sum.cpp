
class Solution {
public:
    int maxSum=INT_MIN;
    int solve(TreeNode* root){
        if(root==NULL)return 0;
        int left=solve(root->left);
        int right=solve(root->right);

        int niche_hi_mil_gaya=left+right+root->val;
        int koi_ek_achha=max(left,right)+root->val;
        int sirf_root_achha=root->val;

        maxSum=max({maxSum,niche_hi_mil_gaya,koi_ek_achha,sirf_root_achha});
        return max({koi_ek_achha,sirf_root_achha});
    }
    int maxPathSum(TreeNode* root) {
         solve(root);
         return maxSum;
    }
};