class Solution {
public:
void solve(TreeNode* root, int k, int &count, vector<int> &path) {
    if (root == NULL) return;

    path.push_back(root->val);

    solve(root->left, k, count, path);
    solve(root->right, k, count, path);

    // Check for k sum
    int size = path.size();
    long long sum = 0;  // Use long long to avoid overflow
    for (int i = size - 1; i >= 0; i--) {
        sum += path[i];
        if (sum == k) {
            count++;
        }
    }

    path.pop_back();
}


    int pathSum(TreeNode* root, int k) {
        vector<int> path;
        int count = 0;
        solve(root, k, count, path);
        return count;
    }
};
