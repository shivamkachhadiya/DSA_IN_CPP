/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int search(vector<int>&inorder,int left,int right,int target){
        for(int i=left;i<=right;i++){
            if(inorder[i]==target)return i;
        }
        return -1;
    }
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int &preidx,int inOrderLeft,int inOrderRight){
        if(inOrderLeft>inOrderRight){
            return NULL;
        }
        TreeNode* root=new TreeNode(preorder[preidx]);
        int findIndexInInOrder=search(inorder,inOrderLeft,inOrderRight,preorder[preidx]);
        preidx++;

        root->left=solve(preorder,inorder,preidx,inOrderLeft,findIndexInInOrder-1);
        root->right=solve(preorder,inorder,preidx,findIndexInInOrder+1,inOrderRight);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preidx=0;
        return solve(preorder,inorder,preidx,0,inorder.size()-1);
    }
};