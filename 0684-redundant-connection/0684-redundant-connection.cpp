class DSU {
public:
    vector<int> parent, size;
    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int find(int x) {
        if (x == parent[x]) {
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);
        if (x_parent == y_parent)
            return;
        if (size[x_parent] < size[y_parent]) {
           parent[x_parent] = y_parent;
            size[y_parent] += size[x_parent];
        } else {
            parent[y_parent] = x_parent;
            size[x_parent] += size[y_parent];
        }
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU dsu(n);
        for (auto& x : edges) {
            int u = x[0];
            int v = x[1];

            if (dsu.find(u) == dsu.find(v)) {
                return x;
            }

            dsu.Union(u, v);
        }
        return {};
    }
};