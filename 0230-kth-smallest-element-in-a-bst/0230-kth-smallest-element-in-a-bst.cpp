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
    vector<int> temp;
    void solveVec(TreeNode* root, int k) {
        if (root == NULL)
            return;
        solveVec(root->left, k);
        temp.push_back(root->val);
        solveVec(root->right, k);
        int size = temp.size();
    }
    int kthSmallest(TreeNode* root, int k) {
         temp.clear();    
        solveVec(root, k);
        return temp[k - 1];        // kth smallest (1‑indexed → k‑1)
    }
};