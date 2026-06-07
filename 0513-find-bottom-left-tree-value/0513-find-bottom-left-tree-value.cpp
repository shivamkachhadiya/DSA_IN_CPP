class Solution {
public:
    int height(TreeNode* root){
        if(root==NULL) return 0;
        return 1 + max(height(root->left), height(root->right));
    }

    int ans = 0;
    bool found = false;

    void solve(TreeNode* root, int &ans, int max_level, int count){
        if(root==NULL || found) return;

        if(count == max_level){
            ans = root->val;
            found = true;
            return;
        }

        if(root->left){
            solve(root->left, ans, max_level, count+1);
        }

        if(found) return;

        if(root->right){
            solve(root->right, ans, max_level, count+1);
        }
    }

    int findBottomLeftValue(TreeNode* root) {
        if(root==NULL) return 0;

        int max_height = height(root) - 1;
        solve(root, ans, max_height, 0);

        return ans;
    }
};