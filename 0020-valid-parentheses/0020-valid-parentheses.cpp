class Solution {
public:
    bool isValid(string str) {
        stack<char>stack;
        for(int i=0;i<str.size();i++){
            if(str[i]=='('||str[i]=='{'||str[i]=='['){
                stack.push(str[i]);
            }else{
                if(stack.size()==0){
                    return false;
                }
                if(stack.top()=='('&&str[i]==')' ||
                   stack.top()=='{'&&str[i]=='}' ||
                   stack.top()=='['&&str[i]==']'){
                    stack.pop();
                   }else{
                    return false;
                   }
            }
        }
        return stack.size()==0;
    }
};