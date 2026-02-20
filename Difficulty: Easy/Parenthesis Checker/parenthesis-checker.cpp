class Solution {
  public:
    bool isBalanced(string& s) {
        // code here
        stack<int>st;
        for(auto ch:s){
            if(ch=='['||ch=='('||ch=='{'){
                st.push(ch);
            }
            else{
                if(st.empty())return false;
                if(ch==']'&& st.top()!='['
                    || ch=='}' && st.top()!='{'
                    || ch==')' && st.top()!='(')
                    {
                            return false;
                    }
                    st.pop();
            }
        }
        
       return st.empty();
    
    }
};