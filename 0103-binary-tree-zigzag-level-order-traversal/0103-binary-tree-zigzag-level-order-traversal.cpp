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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;

        if (root == nullptr)
            return result;

        queue<TreeNode*> q;
        q.push(root);

        bool flag = true; // indicate right->left or left->right

        while (!q.empty()) {
            auto size = q.size();
            vector<int> ans(size);

            for (int i = 0; i < size; i++) {
                auto frontNode = q.front();
                q.pop();

                auto index = flag ? i : size - i - 1;
                ans[index] = frontNode->val;

                if (frontNode->left) {
                    q.push(frontNode->left);
                }
                if (frontNode->right) {
                    q.push(frontNode->right);
                }
            }

            result.push_back(ans);
            flag = !flag;
        }
        return result;
    }
};