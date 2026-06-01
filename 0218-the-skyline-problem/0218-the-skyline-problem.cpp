class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int,int>> events;
        // left edge ko -height, right edge ko +height
        for(auto &b : buildings) {
            events.push_back({b[0], -b[2]});
            events.push_back({b[1], b[2]});
        }
        sort(events.begin(), events.end());
        
        multiset<int> heights = {0}; // ground height
        int prev = 0;
        vector<vector<int>> res;
        
        for(auto &e : events) {
            int x = e.first, h = e.second;
            if(h < 0) heights.insert(-h); // building start
            else heights.erase(heights.find(h)); // building end
            
            int cur = *heights.rbegin(); // max height
            if(cur != prev) {
                res.push_back({x, cur}); // skyline change
                prev = cur;
            }
        }
        return res;
    }
};
