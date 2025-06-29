class Solution {
public:
    deque<int> dq;
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        // analys first window
        int n=arr.size();
        for (int i = 0; i < k; i++) {
            while (dq.size() > 0 && arr[dq.back()] <= arr[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        vector<int> ans;

        // analys remaining
        for (int i = k; i < n; i++) {
            ans.push_back(arr[dq.front()]);

            // remove element which are not part of currunt window
            while(dq.size()&&dq.front()<=i-k){
                dq.pop_front();
            }

            while (dq.size() > 0 && arr[dq.back()] <= arr[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        ans.push_back(arr[dq.front()]);
        return ans;
    }
};
