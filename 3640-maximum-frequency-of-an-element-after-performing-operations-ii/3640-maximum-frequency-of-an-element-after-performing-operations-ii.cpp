class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        // Map to store the frequency of each number in nums
        unordered_map<int, int> frequency;
      
        // Map to track range boundaries for sweep line algorithm
        // Using map (ordered) to process events in sorted order
        map<int, int> rangeBoundaries;

        // Process each number in the input array
        for (int num : nums) {
            // Count frequency of current number
            frequency[num]++;
          
            // Initialize the number in rangeBoundaries (ensures it exists for later)
            rangeBoundaries[num];
          
            // Mark the start of range where current number can contribute
            // Numbers in [num - k, num + k] can be changed to num
            rangeBoundaries[num - k]++;
          
            // Mark the end of range (exclusive) where current number stops contributing
            rangeBoundaries[num + k + 1]--;
        }

        int maxResult = 0;
        int activeCount = 0;  // Count of numbers that can be changed to current position
      
        // Sweep through all positions in sorted order
        for (const auto& [position, delta] : rangeBoundaries) {
            // Update the count of active numbers that can be changed to current position
            activeCount += delta;
          
            // Calculate max frequency achievable at this position:
            // - frequency[position]: numbers already at this position
            // - numOperations: max numbers we can change
            // - activeCount: total numbers available to change to this position
            // Take minimum of available changes and allowed operations
            maxResult = max(maxResult, min(activeCount, frequency[position] + numOperations));
        }

        return maxResult;
    }
};
