class Solution {
    map<pair<int, int>, vector<TreeNode*>> memo;

public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return buildTrees(1, n);
    }

    vector<TreeNode*> buildTrees(int start, int end) {
        if (start > end) return {nullptr};
        if (memo.count({start, end})) return memo[{start, end}];

        vector<TreeNode*> allTrees;
        for (int i = start; i <= end; ++i) {
            vector<TreeNode*> leftSubtrees = buildTrees(start, i - 1);
            vector<TreeNode*> rightSubtrees = buildTrees(i + 1, end);

            for (auto left : leftSubtrees) {
                for (auto right : rightSubtrees) {
                    TreeNode* root = new TreeNode(i, left, right);
                    allTrees.push_back(root);
                }
            }
        }
        return memo[{start, end}] = allTrees;
    }
};