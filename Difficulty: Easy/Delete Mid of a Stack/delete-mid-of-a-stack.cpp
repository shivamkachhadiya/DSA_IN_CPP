class Solution {
  public:
  void solve(stack<int>&s,int count,int size){
      if(count==size/2){
          s.pop();
          return;
      }
      int num=s.top();
      s.pop();
      
      //recursive call
      solve(s,count+1,size);
      s.push(num);
  }
    // Function to delete middle element of a stack.
    void deleteMid(stack<int>& s) {
        // code here..
        int count=0;
        int n=s.size();
        solve(s,count,n);
    }
};