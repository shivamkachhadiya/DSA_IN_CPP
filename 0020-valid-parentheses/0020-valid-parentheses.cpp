class Solution {
    public boolean isValid(String s) {
        Stack<Character> st = new Stack<>();
        for (char i : s.toCharArray()) {
            if (i == '(' || i == '{' || i == '[') {
                st.push(i);
            }else{
                if(st.isEmpty())return false;
                char top_=st.peek();
                st.pop();
                if(i==')'&&top_!='('||i==']'&&top_!='['||i=='}'&&top_!='{')return false;
            }
        }
        return st.isEmpty();
    }
};