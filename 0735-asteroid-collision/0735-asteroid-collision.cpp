class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        stack<int> s;
        vector<int> res;
        for (int i = 0; i < arr.size(); i++) {

            // ❌ Wrong condition
            // if(!s.empty() && s.top() - arr[i] > 0){
            // ✅ Correct: collision only if top > 0 and current < 0
            if (!s.empty() && s.top() > 0 && arr[i] < 0) {
                bool destroyed = false;

                while (!s.empty() && s.top() > 0 && arr[i] < 0) {
                    if (s.top() < -arr[i]) { // stack top smaller → pop
                        s.pop();
                        continue;
                    } else if (s.top() == -arr[i]) { // equal → both destroyed
                        s.pop();
                        destroyed = true;
                        break;
                    } else { // stack top bigger → current destroyed
                        destroyed = true;
                        break;
                    }
                }

                if (!destroyed)
                    s.push(arr[i]); // push negative if it survived
            } else {
                // if no collision → just push
                s.push(arr[i]);
            }
        }

        // ✅ Collect survivors at end (not inside loop)
        while (!s.empty()) {
            res.push_back(s.top());
            s.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
