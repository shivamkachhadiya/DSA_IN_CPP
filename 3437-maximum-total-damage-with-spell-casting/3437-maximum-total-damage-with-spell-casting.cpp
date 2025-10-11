class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        // Sort powers in ascending order for easier processing
        sort(power.begin(), power.end());
      
        // Store the sorted power array and its size
        this->powers = power;
        arraySize = power.size();
      
        // Initialize memoization array and next valid index array
        memo.resize(arraySize, 0);
        nextValidIndex.resize(arraySize);
      
        // Count frequency of each power value and precompute next valid indices
        for (int i = 0; i < arraySize; ++i) {
            // Count occurrences of each power value
            powerFrequency[powers[i]]++;
          
            // Find the next index where power[j] > power[i] + 2
            // This is the next index we can consider if we take power[i]
            nextValidIndex[i] = upper_bound(powers.begin() + i + 1, 
                                           powers.end(), 
                                           powers[i] + 2) - powers.begin();
        }
      
        // Start dynamic programming from index 0
        return calculateMaxDamage(0);
    }

private:
    // Map to store frequency of each power value
    unordered_map<int, int> powerFrequency;
  
    // Memoization array for dynamic programming
    vector<long long> memo;
  
    // Array to store sorted power values
    vector<int> powers;
  
    // Array to store next valid index for each position
    vector<int> nextValidIndex;
  
    // Size of the power array
    int arraySize;

    long long calculateMaxDamage(int index) {
        // Base case: if index is out of bounds, return 0
        if (index >= arraySize) {
            return 0;
        }
      
        // Return memoized result if already calculated
        if (memo[index] != 0) {
            return memo[index];
        }
      
        // Option 1: Skip the current power value entirely
        // Move to the next distinct power value
        long long skipCurrentPower = calculateMaxDamage(index + powerFrequency[powers[index]]);
      
        // Option 2: Take all occurrences of the current power value
        // Calculate damage from current power and continue from next valid index
        long long takeCurrentPower = static_cast<long long>(powers[index]) * powerFrequency[powers[index]] 
                                    + calculateMaxDamage(nextValidIndex[index]);
      
        // Store and return the maximum of both options
        memo[index] = max(skipCurrentPower, takeCurrentPower);
        return memo[index];
    }
};