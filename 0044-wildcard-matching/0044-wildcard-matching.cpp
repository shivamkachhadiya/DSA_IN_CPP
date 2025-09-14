class Solution {
public:
    bool solve(string &str,string pattern,int i,int j){
        //base case
        if(i<0&&j<0){  //dono stream and pattern dono khatam
            return true;
        }
        if(i>=0 && j<0){   //string khatam nahi huaa pattern khatam
            return false;
        }
        if(i<0 && j>=0){   //string khatam pattern khatam nahi huaa
            for(int k=0;k<=j;k++){
                if(pattern[k]!='*'){
                    return false;
                }
            }
            return true;
        }

        //match hoo jaye
        if(str[i]==pattern[j]||pattern[j]=='?'){
            return solve(str,pattern,i-1,j-1);
        }else if(pattern[j]=='*'){
            return (solve(str,pattern,i,j-1)||(solve(str,pattern,i-1,j)));
        }else{
            return false;
        }       

    }
    bool solveDP(string &str,string pattern,int i,int j,vector<vector<int>>&dp){
        //base case
        if(i<0&&j<0){  //dono stream and pattern dono khatam
            return true;
        }
        if(i>=0 && j<0){   //string khatam nahi huaa pattern khatam
            return false;
        }
        if(i<0 && j>=0){   //string khatam pattern khatam nahi huaa
            for(int k=0;k<=j;k++){
                if(pattern[k]!='*'){
                    return false;
                }
            }
            return true;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        //match hoo jaye
        if(str[i]==pattern[j]||pattern[j]=='?'){
            return dp[i][j]= solveDP(str,pattern,i-1,j-1,dp);
        }else if(pattern[j]=='*'){
            return dp[i][j]= (solveDP(str,pattern,i,j-1,dp)||(solveDP(str,pattern,i-1,j,dp)));
        }else{
            return false;
        }       

    }
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        //return solve(s, p, s.size() - 1, p.size() - 1);.
        return solveDP(s, p, n-1, m-1, dp);
        
    }
};