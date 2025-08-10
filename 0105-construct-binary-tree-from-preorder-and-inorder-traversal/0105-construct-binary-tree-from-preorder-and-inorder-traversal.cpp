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
    TreeNode* solve(vector<int>& inorder, vector<int>& preorder, int &index,
                    int inOrderStart, int inOrderEnd, int n,
                    map<int, int>& nodeToIndex) {
        if (index >= n || inOrderStart > inOrderEnd) {
            return NULL;
        }
        int element = preorder[index];
        index++;
        TreeNode* root = new TreeNode(element);
        int position = nodeToIndex[element];

        // recursive for left

        // Build left subtree
        root->left = solve(inorder, preorder, index, inOrderStart, position - 1,
                           n, nodeToIndex);
        // Build right subtree
        root->right = solve(inorder, preorder, index, position + 1, inOrderEnd,
                            n, nodeToIndex);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int preOrderIndex = 0;
        map<int, int> nodeToIndex;
        createMapping(inorder, nodeToIndex, n);
        TreeNode* ans =
            solve(inorder, preorder, preOrderIndex, 0, n - 1, n, nodeToIndex);
        return ans;
    }
};