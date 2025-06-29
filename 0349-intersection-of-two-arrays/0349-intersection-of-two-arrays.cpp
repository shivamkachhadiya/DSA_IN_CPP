#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> setA(nums1.begin(), nums1.end());
        unordered_set<int> intersection;

        for (int num : nums2) {
            if (setA.find(num) != setA.end()) {
                intersection.insert(num); // Store unique common elements
            }
        }

        // Convert set to vector
        return vector<int>(intersection.begin(), intersection.end());
    }
};
