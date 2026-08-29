class Solution {
public:
    int delRow[4]={-1,1,0,0};
    int delCol[4]={0,0,-1,1};
    void dfs(vector<vector<char>>&grid,int i,int j,vector<vector<bool>>&vis,int n,int m){
        vis[i][j]=true;
        for(int k=0;k<4;k++){
            int newRow=i+delRow[k];
            int newCol=j+delCol[k];
            if(newRow<n&&newCol<m&&newRow>=0&&newCol>=0&&vis[newRow][newCol]==false&&grid[newRow][newCol]=='1'){
                dfs(grid,newRow,newCol,vis,n,m);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int islands=0;
        vector<vector<bool>>vis(n,vector<bool>(m,false));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==false&&grid[i][j]=='1'){
                    dfs(grid,i,j,vis,n,m);
                    islands++;
                }
            }
        }
        return islands;
    }
};