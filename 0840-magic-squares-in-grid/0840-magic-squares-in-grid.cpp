class Solution {
public:
    int count=0;
    bool isMagic(vector<vector<int>>&grid,int i,int j){
        vector<int>seen(10,0);
        for(int r=i;r<i+3;r++){
            for(int c=j;c<j+3;c++){
                int val=grid[r][c];
                if(val<1||val>9)return false;
                if(seen[val])return false;
                seen[val]=1;
            }
        }

        for(int row=i;row<i+3;row++){
            int sum=0;
            for(int col=j;col<j+3;col++){
                sum+=grid[row][col];
            }
            if(sum!=15)return false;
        }
        for(int col=j;col<j+3;col++){
            int sum=0;
            for(int row=i;row<i+3;row++){
                sum+=grid[row][col];
            }
            if(sum!=15)return false;
        }
        int d1=grid[i][j]+grid[i+1][j+1]+grid[i+2][j+2];
        int d2=grid[i][j+2]+grid[i+1][j+1]+grid[i+2][j];
        if(d1!=15||d2!=15)return false;
        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n=grid.size(); //3
        int m=grid[0].size(); //4

        for(int i=0;i<=n-3;i++){
            for(int j=0;j<=m-3;j++){
                if(isMagic(grid,i,j)){
                    count++;
                }
            }
        }
        return count;
    }
};