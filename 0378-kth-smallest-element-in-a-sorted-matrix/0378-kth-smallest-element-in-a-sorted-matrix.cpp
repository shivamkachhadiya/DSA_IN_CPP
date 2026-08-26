class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int>pq;
        for(auto &x:matrix){
            for(int i:x){
                pq.push(i);

                if(pq.size()>k){
                    pq.pop();
                }
            }
        }
        return pq.top();
    }
};