/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> ans;
    void solve(TreeNode* root, int target, vector<int>& part, int curr_sum) {
        if (root == NULL)
            return;
        curr_sum += root->val;
        part.push_back(root->val);

        if (root->left == NULL && root->right == NULL) {
            if (curr_sum == target) {
                ans.push_back(part);
            }
            part.pop_back();
            return;
        }
        // explore left and right
        solve(root->left, target, part, curr_sum);
        solve(root->right, target, part, curr_sum);

        // backtrack
        part.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (root == NULL)
            return ans;
        vector<int> part;
        solve(root, targetSum, part, 0);
        return ans;
    }
};