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
    vector<int>ans1;
    vector<int>ans2;
    void solve(TreeNode* root){
        if(root==NULL)return;
        ans1.push_back(root->val);
        solve(root->left);
        solve(root->right);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        solve(root1);
        solve(root2);
        sort(ans1.begin(),ans1.end());
        return ans1;
    }
};