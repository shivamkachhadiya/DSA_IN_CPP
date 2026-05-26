class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> answer(n, 0);
        stack<int> st; // sirf INDEX push karoge

        for (int i = 0; i < n; i++) {
            // Current temp, stack top wale temp se bada hai
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int prevIndex = st.top();
                st.pop();

                // Count = current_index - prev_index
                // This is effectively count baar
                answer[prevIndex] = i - prevIndex;
            }

            // Element ka INDEX push kar do
            st.push(i);
        }

        return answer;
    }
};