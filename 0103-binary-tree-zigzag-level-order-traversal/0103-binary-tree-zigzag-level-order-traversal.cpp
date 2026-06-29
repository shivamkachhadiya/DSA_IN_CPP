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
        if (root == NULL)
            return {};

        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> ans;
        bool left_to_right = true;
        while (!q.empty()) {
            int n = q.size();
            vector<int> part;

            for (int i = 0; i < n; i++) {
                TreeNode* frontNode = q.front();
                q.pop();
                part.push_back(frontNode->val);
                if (frontNode->left)
                    q.push(frontNode->left);
                if (frontNode->right)
                    q.push(frontNode->right);
            }

            if (!left_to_right) {
                reverse(part.begin(), part.end());
            }

            ans.push_back(part);

            left_to_right = !left_to_right;
        }
        return ans;
    }
};