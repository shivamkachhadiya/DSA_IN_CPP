class Solution {
public:
    int delR[4]={-1,1,0,0};
    int delC[4]={0,0,-1,1};
    void dfs(vector<vector<char>>&grid,int n,int m,vector<vector<bool>>&vis,int i,int j){
        vis[i][j]=true;

        for(int x=0;x<4;x++){
            int newRow=i+delR[x];
            int newCol=j+delC[x];
            if(newRow>=0&&newCol>=0&&newRow<n&&newCol<m&&vis[newRow][newCol]==false&&grid[newRow][newCol]=='1'){
                dfs(grid,n,m,vis,newRow,newCol);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int islands=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==false&&grid[i][j]!='0'){
                    dfs(grid,n,m,vis,i,j);
                    islands++;
                }
            }
        }
        return islands;
    }
};