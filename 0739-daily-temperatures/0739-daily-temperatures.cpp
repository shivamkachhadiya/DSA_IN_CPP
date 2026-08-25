class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> ans(n, 0);
        for (int i = n - 1; i >= 0; i--) {
            if (st.empty()) {
                ans[i] = 0;
                st.push(i);
            }
            while(!st.empty()&&arr[i]>=arr[st.top()]){
                st.pop();
            }
            if(!st.empty()){
                ans[i]=st.top()-i;

            }
            st.push(i);
        }
        return ans;
    }
};