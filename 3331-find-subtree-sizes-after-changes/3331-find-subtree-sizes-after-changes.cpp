class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<int> first_child(n, -1), next_sibling(n, -1);  // children as a linked list in two int arrays
        for (int x = n - 1; x > 0; --x) {
            next_sibling[x] = first_child[parent[x]];
            first_child[parent[x]] = x;
        }
        vector<int> size(n, 1), above(n);
        array<int, 26> last;  // last[c]: the deepest node with letter c on the path from the root
        last.fill(-1);
        vector<int> stack{0};  // x enters x, ~x leaves it: no recursion
        while (!stack.empty()) {
            int x = stack.back();
            stack.pop_back();
            if (x >= 0) {
                int c = s[x] - 'a';
                above[x] = last[c];  // the closest ancestor with the same letter, or -1
                last[c] = x;
                stack.push_back(~x);  // leave x after all its children
                for (int child = first_child[x]; child != -1; child = next_sibling[child])
                    stack.push_back(child);
            } else {
                x = ~x;
                last[s[x] - 'a'] = above[x];
                if (x)  // the root has no parent
                    size[above[x] >= 0 ? above[x] : parent[x]] += size[x];
            }
        }
        return size;
    }
};

inline auto init = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 'c';
}();