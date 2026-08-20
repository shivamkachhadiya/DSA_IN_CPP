class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        vector<int>ans(arr.size(),0);
        stack<int>st;
        int n=arr.size();
    
        for(int i=n-1;i>=0;i--){
            while(st.empty()==false&&arr[st.top()]<=arr[i]){
                st.pop();
            }
            if(st.empty()==true){
                ans[i]=0;
                st.push(i);
            }
            if(st.empty()==false){
                int top_idx=st.top();
                int curr_idx=i;
                int diff=top_idx-curr_idx;
                ans[i]=diff;
                st.push(i);
            }
        }
        return ans;
    }
};