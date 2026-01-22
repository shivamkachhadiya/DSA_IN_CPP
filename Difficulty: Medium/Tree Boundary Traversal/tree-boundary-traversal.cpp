/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    void traverseleft(Node* root,vector<int>&ans){
        //base case
        if(root==NULL){
            return ;
        }
        if(root->left==NULL && root->right==NULL){
            return ;
        }
        ans.push_back(root->data);
        //if situation like
            //  /
            // /
        if(root->left)
            traverseleft(root->left,ans);
            //  /
            //  \
            
        else
            traverseleft(root->right,ans);
    }
    
    void traverseleaf(Node* root,vector<int>&ans){
        if(root==NULL)
            return;
        if(root->left==NULL && root->right==NULL){
            ans.push_back(root->data);
            return;
        }
        traverseleaf(root->left,ans);
        traverseleaf(root->right,ans);
            
}
    void traverseright(Node* root,vector<int>&ans){
        if(root==NULL)return;
        
        if(root->left==NULL && root->right==NULL){
            return ;
        }
        if(root->right)
            traverseright(root->right,ans);
        else
            traverseright(root->left,ans);
        ans.push_back(root->data);
        
    }
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int>ans;
        if(root==NULL){
            return ans;
        }
        ans.push_back(root->data);
        //left part
        traverseleft(root->left,ans);
        
        //leaf node
        traverseleaf(root->left,ans);  //left subtree
        traverseleaf(root->right,ans);  //right subtree
        
        //right part
        traverseright(root->right,ans);
        return ans;
    }
};