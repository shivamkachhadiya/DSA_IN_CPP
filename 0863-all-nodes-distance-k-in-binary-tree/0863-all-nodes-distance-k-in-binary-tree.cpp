/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, vector<TreeNode*>> graph;

    void build(TreeNode* node) {
        if (!node)
            return;

        if (node->left) {
            graph[node].push_back(node->left);
            graph[node->left].push_back(node);
            build(node->left);
        }

        if (node->right) {
            graph[node].push_back(node->right);
            graph[node->right].push_back(node);
            build(node->right);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        build(root);
        queue<TreeNode*> q;
        unordered_set<TreeNode*> vis;

        q.push(target);
        vis.insert(target);

        int dist = 0;

        while (!q.empty()) {

            int sz = q.size();

            if (dist == k)
                break;

            while (sz--) {

                TreeNode* cur = q.front();
                q.pop();

                for (TreeNode* nei : graph[cur]) {

                    if (!vis.count(nei)) {
                        vis.insert(nei);
                        q.push(nei);
                    }
                }
            }

            dist++;
        }
        vector<int> ans;

        while (!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};