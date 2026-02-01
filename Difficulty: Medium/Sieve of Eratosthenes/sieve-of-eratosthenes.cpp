class Solution {
  public:
    vector<int> sieve(int n) {
   
        int prime[n+1];
        for(int i=2;i<=n;i++){
            prime[i]=1;
        }
        for(int i=2;i<=n;i++){
            if(prime[i]==1){
                for(int j=2*i;j<=n;j+=i){
                    prime[j]=0;
                }
            }
        }
        vector<int>res;
        for(int i=2;i<=n;i++){
            if(prime[i]==1){
               res.push_back(i);
            }
        }
        return res;
    }
};