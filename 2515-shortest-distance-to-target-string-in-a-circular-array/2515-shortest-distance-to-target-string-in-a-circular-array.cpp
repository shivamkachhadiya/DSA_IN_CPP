class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
          int arraySize = words.size();
        int minDistance = arraySize;  
      
        for (int currentIndex = 0; currentIndex < arraySize; ++currentIndex) {
            string currentWord = words[currentIndex];
          
            if (currentWord == target) {
                int directDistance = abs(currentIndex - startIndex);
              
                int wrapAroundDistance = arraySize - directDistance;
              
                minDistance = min(minDistance, min(directDistance, wrapAroundDistance));
            }
        }
      
        return minDistance == arraySize ? -1 : minDistance;
    }
};