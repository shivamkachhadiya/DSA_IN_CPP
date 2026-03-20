class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_surplus = 0;
        int current_surplus = 0;
        int start_node = 0;

        for (int i = 0; i < gas.size(); i++) {
            int net_gain = gas[i] - cost[i];
            total_surplus += net_gain;
            current_surplus += net_gain;

            if (current_surplus < 0) {
                start_node = i + 1; 
                current_surplus = 0; // Reset for the new starting attempt
            }
        }

        return (total_surplus < 0) ? -1 : start_node;
    }
};