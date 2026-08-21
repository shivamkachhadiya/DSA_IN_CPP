class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        queue<pair<int,pair<int,int>>>q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    vis[i][j]=true;
                    q.push({0,{i,j}});
                }
            }
        }

        int delRow[]={-1,1,0,0};
        int delCol[]={0,0,-1,1};
        int ans=0;
        while(!q.empty()){
            int time=q.front().first;
            int row=q.front().second.first;
            int col=q.front().second.second;

            q.pop();
            ans=max(ans,time);

            for(int k=0;k<4;k++){
                int newRow=row+delRow[k];
                int newCol=col+delCol[k];
                if(newRow>=0&&newCol>=0&&newRow<n&&newCol<m&&vis[newRow][newCol]==false&&grid[newRow][newCol]==1){
                    vis[newRow][newCol]=true;
                    q.push({time+1,{newRow,newCol}});
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1&&vis[i][j]==false){
                    return -1;
                }
            }
        }
        return ans;

    }
};