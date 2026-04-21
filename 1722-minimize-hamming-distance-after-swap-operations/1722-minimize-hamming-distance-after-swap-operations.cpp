class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
      
        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0); 
      
        function<int(int)> f_root = [&](int x) {
            if (x == parent[x]) {
                return x;
            }
            return parent[x] = f_root(parent[x]);
        };
      
        for (auto& swap : allowedSwaps) {
            int root1 = f_root(swap[0]);
            int root2 = f_root(swap[1]);
            parent[root1] = root2; 
        }
        unordered_map<int, unordered_map<int, int>> compoValCount;
        for (int i = 0; i < n; ++i) {
            int root = f_root(i);
            compoValCount[root][source[i]]++;
        }
      
        int hammingDistance = 0;
        for (int i = 0; i < n; ++i) {
            int root = f_root(i);
            if (--compoValCount[root][target[i]] < 0) {
                hammingDistance++;
            }
        }
      
        return hammingDistance;
    }
};