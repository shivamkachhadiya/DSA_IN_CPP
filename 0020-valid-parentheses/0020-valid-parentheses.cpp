class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(auto &i:s){
            if(i=='('||i=='{'||i=='['){
                st.push(i);
            }else{
                if(st.empty())return false;
                char top_=st.top();
                st.pop();
                if(i==')'&&top_!='('||i==']'&&top_!='['||i=='}'&&top_!='{')return false;
            }
        }
        return st.empty();

    }
};