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
    
    int solve(TreeNode* root,int &maxi){
        if(root==NULL)return 0;
        int left_ans=solve(root->left,maxi);
        int right_ans=solve(root->right,maxi);

        int case_1=root->val+left_ans+right_ans;
        int case_2=root->val+max(left_ans,right_ans);
        int case_3=root->val;

        maxi=max({maxi,case_1,case_2,case_3});
        return max({case_2,case_3});
    }
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
         solve(root,maxi);
         return maxi;
         
    }
};