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
    vector<int>sum_vec;
    void solve(TreeNode* root,int currsum){
        if(root==NULL)return;
        //495 push in sum_vec
        currsum = currsum * 10 + root->val;
        if (root->left == nullptr && root->right == nullptr) {
            sum_vec.push_back(currsum);
            return;
        }
        solve(root->left,currsum);
        solve(root->right,currsum);
    }
    int sumNumbers(TreeNode* root) {
        solve(root,0);
        return accumulate(sum_vec.begin(),sum_vec.end(),0);
    }
};