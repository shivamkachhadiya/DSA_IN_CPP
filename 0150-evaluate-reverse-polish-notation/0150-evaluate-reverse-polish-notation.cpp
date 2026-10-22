class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        //int ans=0;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]!="+"&&tokens[i]!="-"&&tokens[i]!="/"&&tokens[i]!="*"){
                int currElemenet=stoi(tokens[i]);
                st.push(currElemenet);
            }else{
                int n1=st.top();
                st.pop();
                int n2=st.top();
                st.pop();
                string operation=tokens[i];
                if(operation=="+"){
                    int ans=n1+n2;
                    st.push(ans);
                }else if(operation=="-"){
                    int ans=n2-n1;
                    st.push(ans);
                }else if(operation=="/"){
                    int ans=n2/n1;
                    st.push(ans);
                }else if(operation=="*"){
                    int ans=n1*n2;
                    st.push(ans);
                }else{
                    return -1;
                }
            }
        }
        return st.top();
    }
};