class Solution {
public:
    vector<string> solve(string par,int start,int end,vector<string>&ans,int n){
        if(par.size()==n*2){
            ans.push_back(par);
        }

        if(start<n){
            solve(par+"(",start+1,end,ans,n);
        }

        if(end<start){
            solve(par+")",start,end+1,ans,n);
        }

        return ans;


    }
    vector<string> generateParenthesis(int n) {
  
        vector<string>ans;
       vector<string>s=solve("",0,0,ans,n);
       return s;

    }
};