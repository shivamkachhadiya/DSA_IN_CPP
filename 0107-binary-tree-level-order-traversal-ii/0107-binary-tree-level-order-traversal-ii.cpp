class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        
        queue<TreeNode*> q;
        q.push(root);
        
        // BFS traversal karenge
        while (!q.empty()) {
            int size = q.size();
            vector<int> level;
            
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);
                
                // left child add karo
                if (node->left) q.push(node->left);
                // right child add karo
                if (node->right) q.push(node->right);
            }
            
            // har level ko res me dalte hain
            res.push_back(level);
        }
        
        // niche se upar chahiye to reverse karna hoga
        reverse(res.begin(), res.end());
        return res;
    }
};
