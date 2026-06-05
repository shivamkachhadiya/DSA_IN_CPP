class NumArray {
    vector<int> bit;
    vector<int> arr;
    int n;
    
    void add(int idx, int val) {
        for (++idx; idx <= n; idx += idx & -idx) {
            bit[idx] += val;
        }
    }
    
    int prefixSum(int idx) {
        int sum = 0;
        for (++idx; idx > 0; idx -= idx & -idx) {
            sum += bit[idx];
        }
        return sum;
    }
    
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        bit.assign(n+1, 0);
        arr = nums;
        for (int i = 0; i < n; i++) {
            add(i, nums[i]); // initialize BIT
        }
    }
    
    void update(int index, int val) {
        int diff = val - arr[index];
        arr[index] = val;
        add(index, diff); // update BIT
    }
    
    int sumRange(int left, int right) {
        return prefixSum(right) - prefixSum(left-1); // range sum
    }
};
