class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int leftCount = 0;
        int rightCount = 0;
        int wildcardCount = 0;
      
        for (char move : moves) {
            if (move == 'L') {
                leftCount++;
            } else if (move == 'R') {
                rightCount++;
            } else if (move == '_') {
                wildcardCount++;
            }
        }
      
    
        return abs(leftCount - rightCount) + wildcardCount;
    }
};
