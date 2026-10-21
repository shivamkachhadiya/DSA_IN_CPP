class Solution {
    public List<Integer> fallingSquares(int[][] positions) {
        int n = positions.length;
        Map<Integer, Integer> cc = coorCompression(positions);
        int best = 0;
        List<Integer> res = new ArrayList<>();
        SegmentTree tree = new SegmentTree(cc.size());
        for (int[] pos : positions) {
            int L = cc.get(pos[0]);
            int R = cc.get(pos[0] + pos[1] - 1);
            int h = tree.query(L, R) + pos[1];
            tree.update(L, R, h);
            best = Math.max(best, h);
            res.add(best);
        }
        return res;
    }
    
    private Map<Integer, Integer> coorCompression(int[][] positions) {
        Set<Integer> set = new HashSet<>();
        for (int[] pos : positions) {
            set.add(pos[0]);
            set.add(pos[0] + pos[1] - 1);
        }
        List<Integer> list = new ArrayList<>(set);
        Collections.sort(list);
        Map<Integer, Integer> map = new HashMap<>();
        int t = 0;
        for (int pos : list) map.put(pos, t++);
        return map;
    }
    
    class SegmentTree {
        int[] tree;
        int[] lazy;
        int N;
        
        SegmentTree(int N) {
            this.N = N;
            int n = (1 << ((int) Math.ceil(Math.log(N) / Math.log(2)) + 1));
            tree = new int[n];
            lazy = new int[n];
        }
        
        public int query(int L, int R) {
            return queryUtil(1, 0, N - 1, L, R);
        }
        
        private int queryUtil(int index, int s, int e, int L, int R) {
            if (lazy[index] != 0) {
                // apply lazy to node
                int update = lazy[index];
                lazy[index] = 0;
                tree[index] = Math.max(tree[index], update);
                // check if this is leaf
                if (s != e) {
                    lazy[2 * index] = Math.max(lazy[2 * index], update);
                    lazy[2 * index + 1] = Math.max(lazy[2 * index + 1], update);
                }
            }
            // out of range
            if (s > e || s > R || e < L) {
                return 0;
            }
            // [L, R] cover [s, e]
            if (s >= L && e <= R) {
                return tree[index];
            }
            // Overlapped
            int mid = s + (e - s) / 2;
            return Math.max(queryUtil(2 * index, s, mid, L, R), queryUtil(2 * index + 1, mid + 1, e, L, R));
        }
        
        public void update(int L, int R, int h) {
            updateUtil(1, 0, N - 1, L, R, h);
        }
        
        private void updateUtil(int index, int s, int e, int L, int R, int h) {
            if (lazy[index] != 0) {
                // apply lazy to node
                int update = lazy[index];
                lazy[index] = 0;
                tree[index] = Math.max(tree[index], update);
                // check if this is leaf
                if (s != e) {
                    lazy[2 * index] = Math.max(lazy[2 * index], update);
                    lazy[2 * index + 1] = Math.max(lazy[2 * index + 1], update);
                }
            }
            // out of range
            if (s > e || s > R || e < L) {
                return;
            }
            if (s >= L && e <= R) {
                tree[index] = Math.max(tree[index], h);
                if (s != e) {
                    lazy[2 * index] = Math.max(lazy[2 * index], h);
                    lazy[2 * index + 1] = Math.max(lazy[2 * index + 1], h);
                }
                return;
            }
            int mid = s + (e - s) / 2;
            updateUtil(2 * index, s, mid, L, R, h);
            updateUtil(2 * index + 1, mid + 1, e, L, R, h);
            tree[index] = Math.max(tree[2 * index], tree[2 * index + 1]);
        }
    }
}