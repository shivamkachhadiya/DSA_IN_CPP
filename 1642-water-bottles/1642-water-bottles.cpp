class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int totalDrunk = numBottles;   // Drink all the bottles we got at first
        int emptyBottles = numBottles; // Keep track of the empties

        // Keep swapping empties for new full bottles while we can
        while (emptyBottles >= numExchange) {
            int newFull = emptyBottles / numExchange; // How many new bottles we get
            totalDrunk += newFull;                    // Guzzle them down
            emptyBottles = emptyBottles % numExchange + newFull; // Update empties left
        }

        return totalDrunk; // That's all we could drink
    }
};
