class Solution {
public:
    int delRow[4]={-1,1,0,0};
    int delCol[4]={0,0,-1,1};

    void dfs(vector<vector<char>>&grid,int n,int m,vector<vector<bool>>&vis,int i,int j){
         if(i<0||j<0||i>=n||j>=m||grid[i][j]=='0'||vis[i][j]==true){
            return;
        }
        vis[i][j]=true;
       
        for(int k=0;k<4;k++){
            int newRow=i+delRow[k];
            int newCol=j+delCol[k];
            dfs(grid,n,m,vis,newRow,newCol);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));

        int counter=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==false&&grid[i][j]=='1'){
                    dfs(grid,n,m,vis,i,j);
                    counter++;
                }
            }
        }
        return counter;
    }
};