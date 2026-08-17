class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        int n = arr.size();
        stack<int>st;
        vector<int> ans(n, 0);
        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }

            if (st.empty()) {
                ans[i] = 0;
                st.push(i);
            }else{
                ans[i]=st.top()-i;
                st.push(i);
            }
        }
        return ans;
    }
};