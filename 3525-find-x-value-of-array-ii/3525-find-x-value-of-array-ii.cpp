constexpr int N=1<<18;

struct Node {
    int prod=1, freq[5]={0};

    inline void init(int x, int k){
        prod=x;
        switch(k){
            case 1: freq[0]=0; break;
            case 2: freq[0]=freq[1]=0; break;
            case 3: freq[0]=freq[1]=freq[2]=0; break;
            case 4: freq[0]=freq[1]=freq[2]=freq[3]=0; break;
            default: freq[0]=freq[1]=freq[2]=freq[3]=freq[4]=0;
        }
        freq[x]=1;                  
    }

    inline void merge(const Node& L, const Node& R, int k){
        int prod0=L.prod*R.prod%k;
        switch(k){
        case 1: 
            freq[0]=L.freq[0]+R.freq[0];
            break;
        // can furthermore unroll the loops 
        // by hand for the case k>1
        default:
            for (int i=0; i<k; i++) freq[i]=L.freq[i];    
            for (int i=0; i<k; i++) {
                int r=L.prod*i%k;
                freq[r]+=R.freq[i];
            }
        }
        prod=prod0; 
    }
};

Node tree[N];

class SegTree {
public:
    int k;
    unsigned n, n2;

    SegTree(const vector<int>& nums, int k) : k(k), n(nums.size()) {
        n2=bit_ceil(n+1);
        build(nums, k, 1, 0, n-1);
    }
    void build(const vector<int>& nums, int k, int i, int l, int r){
        if (l==r) {
            int v=nums[l]%k;
            tree[i].init(v, k);
            return ;
        }
        const int m=(l+r)>>1;
        build(nums, k, i<<1, l, m);
        build(nums, k, (i<<1)+1, m+1, r);
        tree[i].merge(tree[i<<1], tree[(i<<1)+1], k);
    }

    void update(int idx, int l, int r, int pos, int v) {
        if (l==r){
            tree[idx].init(v, k);
            return ;
        }
        const int m=(l+r)>>1;
        if (pos<=m) update(idx<<1, l, m, pos, v);
        else update((idx<<1)+1, m+1, r, pos, v);
        tree[idx].merge(tree[idx<<1], tree[(idx<<1)+1], k);
    }

    Node query(int i, int l, int r, int qL, int qR) const {
        if (qL<=l && r<=qR) return tree[i];
        const int m=(l+r)>>1;
        if (qR<=m) return query(i<<1, l, m, qL, qR);
        if (qL>m) return query((i<<1)+1, m+1, r, qL, qR);
        Node L=query(i<<1, l, m, qL, qR), R=query((i<<1)+1, m+1, r, qL, qR);
        L.merge(L, R, k);
        return L;
    }
};

class Solution {
public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        const int n=nums.size();
        SegTree seg(nums, k);
        const int qz=queries.size();
        
        vector<int> ans(qz);
        int i=0;
        for (auto& q : queries) {
            const int idx=q[0], v=q[1]%k, s=q[2], x=q[3];
            seg.update(1, 0, n-1, idx, v);
            ans[i++]=seg.query(1, 0, n-1, s, n-1).freq[x];
        }
        return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();