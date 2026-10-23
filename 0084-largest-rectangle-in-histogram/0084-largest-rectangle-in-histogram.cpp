class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>left(n,0);
        vector<int>right(n,0);
        stack<int>st;

        for(int i=0;i<n;i++){
            while(!st.empty()&&heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()){
                left[i]=-1;
            }else{
                left[i]=st.top();
            }
            st.push(i);
        }

        while(!st.empty())st.pop();
        
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()){
                right[i]=n;
            }else{
                right[i]=st.top();
            }
            st.push(i);
        }

        int ans=0;
        for(int i=0;i<n;i++){
            int width=right[i]-left[i]-1;
            int currArea=heights[i]*width;
            ans=max(ans,currArea);
        }
        return ans;
    }
};