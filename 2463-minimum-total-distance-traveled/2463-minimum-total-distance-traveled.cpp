using ll = long long;

class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        vector<vector<ll>> dp(robot.size(), vector<ll>(factory.size()));
        function<ll(int, int)> dfs = [&](int robotIdx, int factoryIdx) -> ll {
            if (robotIdx == robot.size()) {
                return 0;
            }
            if (factoryIdx == factory.size()) {
                return 1e15;  
            }
            if (dp[robotIdx][factoryIdx]) {
                return dp[robotIdx][factoryIdx];
            }
          
            ll minDistance = dfs(robotIdx, factoryIdx + 1);
          
            ll accumulatedDistance = 0;
            int factoryCapacity = factory[factoryIdx][1];
            int factoryPosition = factory[factoryIdx][0];
          
            for (int k = 0; k < factoryCapacity; ++k) {
                if (robotIdx + k >= robot.size()) {
                    break;
                }
                accumulatedDistance += abs(robot[robotIdx + k] - factoryPosition);
              
                minDistance = min(minDistance, accumulatedDistance + dfs(robotIdx + k + 1, factoryIdx + 1));
            }
          
            dp[robotIdx][factoryIdx] = minDistance;
            return minDistance;
        };
        return dfs(0, 0);
    }
};
