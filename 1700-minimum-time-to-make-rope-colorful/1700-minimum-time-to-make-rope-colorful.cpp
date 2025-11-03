class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int totalCost = 0;
        int n = colors.size();
      
        // Process groups of consecutive balloons with the same color
        for (int groupStart = 0, groupEnd = 0; groupStart < n; groupStart = groupEnd) {
            groupEnd = groupStart;
            int groupSum = 0;      // Sum of removal times for current group
            int maxTime = 0;       // Maximum removal time in current group
          
            // Find all consecutive balloons with the same color
            while (groupEnd < n && colors[groupEnd] == colors[groupStart]) {
                groupSum += neededTime[groupEnd];
                maxTime = max(maxTime, neededTime[groupEnd]);
                ++groupEnd;
            }
          
            // If group has more than 1 balloon, remove all except the one with max time
            // Cost = sum of all times - maximum time (keep the most expensive one)
            if (groupEnd - groupStart > 1) {
                totalCost += groupSum - maxTime;
            }
        }
      
        return totalCost;
    }
};