class Solution {
public:
    void reverseString(vector<char>& s) {
        //==========use two pointer=================
        // int n=s.size();
        // int start=0;
        // int end=n-1;
        // while(start<=end){
        //     swap(s[start],s[end]);
        //     start++;
        //     end--;
        // }
        //================use stack======================
        stack<char>st;
        int i=0;
        int n=s.size();
        while(i<n){
            st.push(s[i]);
            i++;
        }
        s.clear();
        
        while(!st.empty()){
            char val=st.top();
            st.pop();
            s.push_back(val);
        }

    
    }
};