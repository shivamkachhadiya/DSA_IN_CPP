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
    TreeNode* solve(vector<int>&preorder, int mini,int maxi, int &index){
        if(index>=preorder.size()){
            return NULL;
        }
        if(preorder[index]<mini||preorder[index]>maxi){
            return NULL;
        }
        TreeNode* root=new TreeNode(preorder[index]);
        index++;
        root->left=solve(preorder,mini,root->val,index);
        root->right=solve(preorder,root->val,maxi,index);

        return root;


    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int mini=INT_MIN;
        int maxi=INT_MAX;
        int i=0;
        return solve(preorder,mini,maxi,i);

        

        
    }
};