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
    vector<long long> ans;
    long long temp_ans = 0;
    void solve(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            temp_ans = 0;
            int sz = q.size(); // Size capture before loop

            for (int i = 0; i < sz; i++) {
                TreeNode* frontNode = q.front();
                // ans.push_back(frontNode->data);
                temp_ans += frontNode->val;
                q.pop();
                if (frontNode->left)
                    q.push(frontNode->left);
                if (frontNode->right)
                    q.push(frontNode->right);
            }
            ans.push_back(temp_ans);
        }
    }
    long long kthLargestLevelSum(TreeNode* root, int k) {
        solve(root);
        if (k > ans.size())
            return -1;

        sort(ans.begin(), ans.end(), greater<long long>());
        return ans[k-1];
    }
};