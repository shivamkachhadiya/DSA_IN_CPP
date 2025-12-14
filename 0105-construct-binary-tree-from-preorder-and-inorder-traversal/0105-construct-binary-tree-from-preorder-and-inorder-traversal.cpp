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
    int findpos(vector<int>& in, int element, int n) {
        for (int i = 0; i < n; i++) {
            if (in[i] == element) {
                return i;
            }
        }
        return -1;
    }
    TreeNode* solve(vector<int>& in, vector<int>& pre, int &index,
                    int inOrderStart, int inorderEnd, int n) {
        if (index >= n || inOrderStart > inorderEnd) {
            return NULL;
        }
        int element = pre[index++];
        TreeNode* root = new TreeNode(element);
        int position = findpos(in, element, n);

        //recursive calls

        root->left=solve(in,pre,index,inOrderStart,position-1,n);
        

        root->right=solve(in,pre,index,position+1,inorderEnd,n);

        return root;

    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preOrderIndex = 0;
        int n = inorder.size();
        TreeNode* ans = solve(inorder, preorder, preOrderIndex, 0, n - 1, n);

        return ans;
    }
};