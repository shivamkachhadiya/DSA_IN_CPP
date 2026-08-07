class Solution {
public:
    bool solve(int n,int m,vector<vector<char>>&mat,int i,int j,string word,int idx){
        if(idx==word.size())return true;
        if(i<0||j<0||i>=n||j>=m||mat[i][j]=='$')return false;
        if(mat[i][j]!=word[idx])return false;
        char temp=mat[i][j];
        mat[i][j]='$';
//{
        //furthr call up left right down
        if(solve(n,m,mat,i+1,j,word,idx+1))return true;
        if(solve(n,m,mat,i,j+1,word,idx+1))return true;
        if(solve(n,m,mat,i-1,j,word,idx+1))return true;
        if(solve(n,m,mat,i,j-1,word,idx+1))return true;
//}
        mat[i][j]=temp;
        return false;
    }
    bool exist(vector<vector<char>>& mat, string word) {
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==word[0]&&solve(n,m,mat,i,j,word,0)){
                    return true;
                }
            }
        }
        return false;
    }
};