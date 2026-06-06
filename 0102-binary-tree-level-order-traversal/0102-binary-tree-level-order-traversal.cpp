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
    void solve(TreeNode* root,vector<vector<int>>&ans){
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            vector<int>part;
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* FrontNode=q.front();
                part.push_back(FrontNode->val);
                q.pop();
                if(FrontNode->left)q.push(FrontNode->left);
                if(FrontNode->right)q.push(FrontNode->right);
            }
            ans.push_back(part);
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL)return ans;
        vector<int>part;
        solve(root,ans);
        return ans;
    }
};