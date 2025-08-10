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
    void createMapping(vector<int>& inorder, map<int, int>& nodeToIndex,
                       int n) {
        for (int i = 0; i < n; i++) {
            nodeToIndex[inorder[i]] = i;
        }
    }
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int& index,
                    int inOrderStart, int inOrderEnd, int n,
                    map<int, int>& nodeToIndex) {
        if (index < 0 || inOrderStart > inOrderEnd) {
            return NULL;
        }
        int element = postorder[index];
        index--;
        TreeNode* root = new TreeNode(element);
        int position = nodeToIndex[element];

        // recursive for left

        // IMPORTANT: build right subtree first for postorder
        root->right = solve(inorder, postorder, index, position + 1, inOrderEnd,
                            n, nodeToIndex);
        root->left = solve(inorder, postorder, index, inOrderStart,
                           position - 1, n, nodeToIndex);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        int postorderIndex = n - 1;
        map<int, int> nodeToIndex;
        createMapping(inorder, nodeToIndex, n);
        TreeNode* ans =
            solve(inorder, postorder, postorderIndex, 0, n - 1, n, nodeToIndex);
        return ans;
    }
};