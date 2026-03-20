#include <unordered_map>
#include <vector>
#include <cstdlib>

class RandomizedSet {
private:
    std::unordered_map<int, int> valToIndex;
    std::vector<int> nums;

public:
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if (valToIndex.find(val) != valToIndex.end()) {
            return false; // Already exists
        }
        
        valToIndex[val] = nums.size();
        nums.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if (valToIndex.find(val) == valToIndex.end()) {
            return false; // Doesn't exist
        }
        
        int indexToRemove = valToIndex[val];
        int lastElement = nums.back();
        
        nums[indexToRemove] = lastElement;
        valToIndex[lastElement] = indexToRemove;
        
        nums.pop_back();
        valToIndex.erase(val);
        
        return true;
    }
    
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};