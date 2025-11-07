class Solution {
public:
    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();
      
        // Step 1: Calculate initial power coverage using difference array technique
        // diff[i] represents the change in power at position i
        long diff[n + 1];
        memset(diff, 0, sizeof diff);
      
        // For each station, add its contribution to all cities in its range
        for (int i = 0; i < n; ++i) {
            int leftBound = max(0, i - r);
            int rightBound = min(i + r, n - 1);
            diff[leftBound] += stations[i];
            diff[rightBound + 1] -= stations[i];
        }
      
        // Step 2: Build prefix sum array to get actual power at each city
        long prefixPower[n + 1];
        prefixPower[0] = diff[0];
        for (int i = 1; i < n + 1; ++i) {
            prefixPower[i] = prefixPower[i - 1] + diff[i];
        }
      
        // Step 3: Binary search helper - check if minimum power targetPower is achievable
        auto canAchieveMinPower = [&](long targetPower, int availableStations) {
            // Use difference array to track additional stations placed
            long additionalDiff[n + 1];
            memset(additionalDiff, 0, sizeof additionalDiff);
            long additionalPower = 0;
          
            // Check each city from left to right
            for (int i = 0; i < n; ++i) {
                // Update additional power from previously placed stations
                additionalPower += additionalDiff[i];
              
                // Calculate power deficit at current city
                long currentPower = prefixPower[i] + additionalPower;
                long deficit = targetPower - currentPower;
              
                if (deficit > 0) {
                    // Need to place stations to cover deficit
                    if (availableStations < deficit) {
                        return false;  // Not enough stations available
                    }
                  
                    // Place stations at the rightmost position that can cover city i
                    // This greedy placement maximizes coverage for future cities
                    availableStations -= deficit;
                    int placementPos = min(i + r, n - 1);
                    int coverageLeft = max(0, placementPos - r);
                    int coverageRight = min(placementPos + r, n - 1);
                  
                    // Update difference array for the new stations' coverage
                    additionalDiff[coverageLeft] += deficit;
                    additionalDiff[coverageRight + 1] -= deficit;
                    additionalPower += deficit;
                }
            }
            return true;
        };
      
        // Step 4: Binary search for maximum achievable minimum power
        long left = 0;
        long right = 1e12;  // Upper bound for power value
      
        while (left < right) {
            long mid = (left + right + 1) >> 1;  // Ceiling division to avoid infinite loop
          
            if (canAchieveMinPower(mid, k)) {
                left = mid;  // Can achieve mid, try for higher
            } else {
                right = mid - 1;  // Cannot achieve mid, try lower
            }
        }
      
        return left;
    }
};
