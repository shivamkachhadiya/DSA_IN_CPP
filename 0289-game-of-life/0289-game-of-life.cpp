class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        vector<int> dirs = {-1,0,1};
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                int live = 0;
                for(int dx : dirs) {
                    for(int dy : dirs) {
                        if(dx==0 && dy==0) continue;
                        int x = i+dx, y = j+dy;
                        if(x>=0 && y>=0 && x<m && y<n && (board[x][y]==1 || board[x][y]==2)) {
                            live++;
                        }
                    }
                }
                // encode next state
                if(board[i][j]==1 && (live<2 || live>3)) board[i][j] = 2; // live->dead
                if(board[i][j]==0 && live==3) board[i][j] = 3; // dead->live
            }
        }
        
        // finalize states
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(board[i][j]==2) board[i][j]=0;
                else if(board[i][j]==3) board[i][j]=1;
            }
        }
    }
};
