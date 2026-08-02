class Solution {
public:
    int ans = 1;

    int dfs(int node, int parentNode, vector<vector<int>>& adj, string& s) {
        int longest = 0;
        int secondLongest = 0;

        for (int child : adj[node]) {
            // Parent ke paas wapas mat jao
            if (child == parentNode)
                continue;

            // Child subtree ki longest branch
            int childLength = dfs(child, node, adj, s);

            // Same character allowed nahi hai
            if (s[node] == s[child])
                continue;

            // longest aur secondLongest update karo
            if (childLength > longest) {
                secondLongest = longest;
                longest = childLength;
            } else if (childLength > secondLongest) {
                secondLongest = childLength;
            }
        }

        // Is node ko center maan ke answer update
        ans = max(ans, longest + secondLongest + 1);

        // Parent ko sirf ek best branch return hogi
        return longest + 1;
    }
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> adj(n);

        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
            adj[i].push_back(parent[i]);
        }
        dfs(0, -1, adj, s);

        return ans;
    }
};