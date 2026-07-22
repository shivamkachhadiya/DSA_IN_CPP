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
    unordered_map<int,int>map;
    void inOrder(TreeNode* root){
        if(root==NULL)return;
        inOrder(root->left);
        //kuch kuch kro
        int val=root->val;
        map[val]++;
        inOrder(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        inOrder(root);
        vector<int>ans;
        int maxi=0;
        for(auto i:map){
          maxi=max(maxi,i.second);
        }
        for(auto x:map){
            if(x.second==maxi){
                ans.push_back(x.first);
            }
        }
        return ans;
    }
};