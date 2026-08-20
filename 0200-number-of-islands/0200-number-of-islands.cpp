class Solution {
public:
    int delRow[4]={-1,1,0,0};
    int delCol[4]={0,0,-1,1};

    void dfs(vector<vector<char>>&grid,vector<vector<bool>>&vis,int n,int m,int i,int j){
        vis[i][j]=true;
        for(int k=0;k<4;k++){
            int newRow=i+delRow[k];
            int newCol=j+delCol[k];
            if(newRow>=0&&newCol>=0&&newRow<n&&newCol<m&&!vis[newRow][newCol]&&grid[newRow][newCol]=='1'){
                dfs(grid,vis,n,m,newRow,newCol);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int count=0;
        
        int m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==false&&vis[i][j]==false&&grid[i][j]=='1'){
                    dfs(grid,vis,n,m,i,j);
                    count++;
                }
            }
        }
        return count;
    }
};