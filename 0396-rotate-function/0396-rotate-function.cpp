class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int currentFunctionValue = 0;
        int sumOfAllElements = 0;
        int arraySize = nums.size();
        for (int i = 0; i < arraySize; ++i) {
            currentFunctionValue += i * nums[i];
            sumOfAllElements += nums[i];
        }
      
        int maxFunctionValue = currentFunctionValue;
      
        for (int rotation = 1; rotation < arraySize; ++rotation) {
            currentFunctionValue = currentFunctionValue + sumOfAllElements - arraySize * nums[arraySize - rotation];
          
            maxFunctionValue = max(maxFunctionValue, currentFunctionValue);
        }
      
        return maxFunctionValue;
    }
};