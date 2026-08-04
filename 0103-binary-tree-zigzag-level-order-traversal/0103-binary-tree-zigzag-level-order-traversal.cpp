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

        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if (root == NULL)
            return ans;
        q.push(root);
        bool left_to_right = true;
        while (!q.empty()) {
            int size = q.size();
            vector<int> part;
            for (int i = 0; i < size; i++) {
                TreeNode* front_node = q.front();
                q.pop();
                part.push_back(front_node->val);
                if (front_node->left)
                    q.push(front_node->left);
                if (front_node->right)
                    q.push(front_node->right);
            }
            if(!left_to_right){
                reverse(part.begin(),part.end());
            }
            ans.push_back(part);
            left_to_right=!left_to_right;
        }
        return ans;
    }
};