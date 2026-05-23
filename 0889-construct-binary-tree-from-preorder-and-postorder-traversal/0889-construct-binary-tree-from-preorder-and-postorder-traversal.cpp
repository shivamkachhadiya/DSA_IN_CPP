class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        unordered_map<int, int> postIndex;
        for (int i = 0; i < postorder.size(); i++) {
            postIndex[postorder[i]] = i;
        }
        return build(preorder, 0, preorder.size() - 1, postorder, 0, postorder.size() - 1, postIndex);
    }

    TreeNode* build(vector<int>& preorder, int preStart, int preEnd,
                    vector<int>& postorder, int postStart, int postEnd,
                    unordered_map<int, int>& postIndex) {
        if (preStart > preEnd || postStart > postEnd) return nullptr;
        TreeNode* root = new TreeNode(preorder[preStart]);
        if (preStart == preEnd) return root;
        int leftRootVal = preorder[preStart + 1];
        int leftRootIdx = postIndex[leftRootVal];
        int leftSize = leftRootIdx - postStart + 1;
        root->left = build(preorder, preStart + 1, preStart + leftSize,
                           postorder, postStart, leftRootIdx, postIndex);
        root->right = build(preorder, preStart + leftSize + 1, preEnd,
                            postorder, leftRootIdx + 1, postEnd - 1, postIndex);
        return root;
    }
};
