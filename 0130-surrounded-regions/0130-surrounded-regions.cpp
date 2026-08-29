class Solution {
public:
    int delRow[4]={-1,1,0,0};
    int delCol[4]={0,0,-1,1};
    void dfs(vector<vector<char>>&grid,int n,int m,vector<vector<bool>>&vis,int i,int j){
        vis[i][j]=true;
        for(int k=0;k<4;k++){
            int newRow=delRow[k]+i;
            int newCol=j+delCol[k];
            if(newRow<n&&newCol<m&&newRow>=0&&newCol>=0&&vis[newRow][newCol]==false&&grid[newRow][newCol]=='O'){
                //grid[newRow][newCol]='X';
                dfs(grid,n,m,vis,newRow,newCol);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0||j==0||i==n-1||j==m-1)&&board[i][j]=='O'&&vis[i][j]==false){
                    dfs(board,n,m,vis,i,j);
                }
            }
        }

        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(vis[i][j]==false&&board[i][j]=='O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};