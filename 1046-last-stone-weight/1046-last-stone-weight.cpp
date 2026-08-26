class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // max heap banate hain
        priority_queue<int> pq(stones.begin(), stones.end());
        
        while (pq.size() > 1) {
            int y = pq.top(); pq.pop(); // sabse bada
            int x = pq.top(); pq.pop(); // second sabse bada
            
            if (y != x) {
                pq.push(y - x); // difference wapas push karo
            }
        }
        
        return pq.empty() ? 0 : pq.top();
    }
};
