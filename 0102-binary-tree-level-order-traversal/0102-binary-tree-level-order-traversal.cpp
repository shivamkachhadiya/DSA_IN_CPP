class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL)return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size_=q.size();
            vector<int>part;
            for(int i=0;i<size_;i++){
                TreeNode* frotNode=q.front();
                q.pop();
                part.push_back(frotNode->val);
                if(frotNode->left!=NULL)q.push(frotNode->left);
                if(frotNode->right!=NULL)q.push(frotNode->right);
            }
            ans.push_back(part);
        }
        return ans;
    }
};