  #include <bits/stdc++.h>
  using namespace std;
  
  static const auto fast_io = []() {
      std::ios_base::sync_with_stdio(false);
      std::cin.tie(nullptr);
      return 0;
  }();
  
  /*
   * Safe Buffer Sizing:
   * - LeetCode hard memory limit is usually ~256MB to 512MB per execution.
   * - 32MB (0x2000000) or 64MB (0x4000000) is plenty for dynamic node allocations 
   *   (e.g., std::unordered_set, std::unordered_map, trees) without triggering MLE.
   */
  
  constexpr size_t BUFFER_SIZE = 0x2000000; // 32 MB buffer
  alignas(std::max_align_t) static char buffer[BUFFER_SIZE];
  static size_t buffer_pos = 0;
  
  void* operator new(size_t size) {
      constexpr size_t alignment = alignof(std::max_align_t);
      size_t padding = (alignment - (buffer_pos % alignment)) % alignment;
      
      // Fallback to std::malloc if the arena buffer is completely exhausted
      if (buffer_pos + padding + size > BUFFER_SIZE) {
          void* ptr = std::malloc(size);
          if (!ptr) throw std::bad_alloc();
          return ptr;
      }
      
      char* aligned_ptr = &buffer[buffer_pos + padding];
      buffer_pos += (size + padding);
      return aligned_ptr;
  }
  
  // Sized & Unsized Delete overrides (no-op for arena speedup)
  void operator delete(void*) noexcept {}
  void operator delete(void*, size_t) noexcept {}
  void operator delete[](void*) noexcept {}
  void operator delete[](void*, size_t) noexcept {}
  
  /*
   *
   * +------------+------------+---------------+
   * | Term       | Contiguous | Order Matters |
   * +------------+------------+---------------+
   * | Subarray   | YES        | YES           |
   * | Substring  | YES        | YES           |
   * | Subsequence| NO         | YES           |
   * | Subset     | NO         | NO            |
   * +------------+------------+---------------+
   */
  
   
//   struct TreeNode {
//       int val;
//       TreeNode *left;
//       TreeNode *right;
//       TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//  };
 

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if((p->val > root->val and q->val < root->val) or (p->val < root->val and q->val > root->val)){
            return root;
        } else if(p->val == root->val or q->val == root->val){
            return root;
        }

        if(p->val < root->val and q->val < root->val){
            return lowestCommonAncestor(root->left , p , q);
        }

        return lowestCommonAncestor(root->right , p , q);


    }
};