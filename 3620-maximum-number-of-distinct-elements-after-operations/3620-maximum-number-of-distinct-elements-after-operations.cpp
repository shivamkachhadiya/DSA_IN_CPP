class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        // Sort the array to process elements in ascending order
        ranges::sort(nums);
      
        // Initialize result counter and previous selected value
        int distinctCount = 0;
        int previousValue = INT_MIN;
      
        // Process each element in sorted order
        for (int currentNum : nums) {
            // Calculate the valid range for current element: [currentNum - k, currentNum + k]
            // We want to pick the smallest valid value that is greater than previousValue
          
            // Lower bound of valid range
            int lowerBound = currentNum - k;
          
            // The minimum valid value we can pick (must be > previousValue)
            int minValidValue = max(lowerBound, previousValue + 1);
          
            // Upper bound of valid range
            int upperBound = currentNum + k;
          
            // The actual value we pick (constrained by upper bound)
            int selectedValue = min(upperBound, minValidValue);
          
            // Check if we can select a valid distinct value
            if (selectedValue > previousValue) {
                // We found a valid distinct value
                distinctCount++;
                previousValue = selectedValue;
            }
        }
      
        return distinctCount;
    }
};