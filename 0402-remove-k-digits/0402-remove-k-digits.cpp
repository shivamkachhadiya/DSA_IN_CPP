class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        //1432219
        for(auto &digit:num){
            while(!st.empty()&&k>0&&st.top()>digit){
                st.pop();
                k--;
            }
            if(st.empty()&&digit=='0')continue;
            st.push(digit);
        }


        while(!st.empty()&&k--)st.pop();

        //build string
        string result="";

        while(!st.empty()){
            result+=st.top();
            st.pop();
        }

        reverse(result.begin(),result.end());

        return result.empty()?"0":result;


        
    }
};