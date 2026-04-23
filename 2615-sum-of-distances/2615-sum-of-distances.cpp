class Solution {
 public:
  vector<long long> distance(vector<int>& nums) {
    vector<long long> ans(nums.size());
    unordered_map<int, vector<int>> n_t_i;

    for (int i = 0; i < nums.size(); ++i)
      n_t_i[nums[i]].push_back(i);

    for (const auto& [_, indices] : n_t_i) {
      const int n = indices.size();
      if (n == 1)
        continue;
      long sum_f = accumulate(indices.begin(), indices.end(), 0L);
      int p_index = 0;
      for (int i = 0; i < n; ++i) {
        sum_f += (i - 1) * (indices[i] - p_index);
        sum_f -= (n - 1 - i) * (indices[i] - p_index);
        ans[indices[i]] = sum_f;
        p_index = indices[i];
      }
    }

    return ans;
  }
};