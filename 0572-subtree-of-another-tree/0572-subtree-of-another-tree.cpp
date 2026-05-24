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
    bool solve(TreeNode* root,TreeNode* subRoot){
        if(root==NULL&& subRoot==NULL)return true;
        if(root==NULL||subRoot==NULL)return false;
        return root->val==subRoot->val&&solve(root->left,subRoot->left)&&solve(root->right,subRoot->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL)return false;
        if(subRoot==NULL)return true;
        if(solve(root,subRoot)){
            return true;
        }
        return isSubtree(root->left,subRoot)||
                    isSubtree(root->right,subRoot);
    
        
    }
};