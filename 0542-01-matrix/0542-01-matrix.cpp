class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>vis(n,vector<int>(m,false));
        vector<vector<int>>dummay(n,vector<int>(m,-1));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    vis[i][j]=true;
                    q.push({{i,j},0});
                    dummay[i][j]=0;
                }
            }
        }
        int delRow[]={-1,+1,0,0};
        int delCol[]={0,0,-1,+1};
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int time=q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int newRow=delRow[i]+row;
                int newCol=delCol[i]+col;
                if(newRow>=0&&newCol>=0&&newRow<n&&newCol<m&&vis[newRow][newCol]==false&&mat[newRow][newCol]==1){
                    vis[newRow][newCol]=true;
                    q.push({{newRow,newCol},time+1});
                    dummay[newRow][newCol]=time+1;
                }
            }
        }
        return dummay;
    }
};