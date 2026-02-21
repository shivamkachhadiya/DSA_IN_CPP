class Solution {
public:

    void createMapping(vector<int>&inorder,map<int,int>&nodeToIndex,int n){
        for(int i=0;i<n;i++){
            nodeToIndex[inorder[i]]=i;
        }
    }

    TreeNode* solve(vector<int>&in,vector<int>&pre,int &index,
                int inorderstart,int inorderend,int n,map<int,int>&nodeToIndex){
                    if(index>=n||inorderstart>inorderend){
                        return nullptr;
                    }
                    int element=pre[index++];
                    TreeNode* root=new TreeNode(element);
                    int position=nodeToIndex[element];

                    root->left=solve(in,pre,index,inorderstart,position-1,n,nodeToIndex);
                    root->right=solve(in,pre,index,position+1,inorderend,n,nodeToIndex);
                    return root;



                }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
       int preorderIndex=0;
       map<int,int>nodeToIndex;
       int n=preorder.size();
       createMapping(inorder,nodeToIndex,n);
       TreeNode* ans=solve(inorder,preorder,preorderIndex,0,n-1,n,nodeToIndex);
       return ans;
    }
};