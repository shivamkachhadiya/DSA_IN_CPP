class Solution {
public:
    int delRow[4]={-1,1,0,0};
    int delCol[4]={0,0,-1,1};
    void dfs(vector<vector<char>>&grid,vector<vector<bool>>&vis,int i,int j,int n,int m){
        vis[i][j]=true;
        
        for(int k=0;k<4;k++){
            int newRow=i+delRow[k];
            int newCol=j+delCol[k];
            if(newRow>=0&&newCol>=0&&newRow<n&&newCol<m&&grid[newRow][newCol]=='1'&&vis[newRow][newCol]==false){
                dfs(grid,vis,newRow,newCol,n,m);
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
                if(vis[i][j]==0&&grid[i][j]=='1'){
                    dfs(grid,vis,i,j,n,m);
                    islands++;
                }
            }
        }
        return islands;
    }
};