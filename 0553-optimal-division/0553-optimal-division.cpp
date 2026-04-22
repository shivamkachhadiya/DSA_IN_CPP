	class Solution {

	public:

	    string optimalDivision(vector<int>& nums) {

	        if (nums.empty()) return "";

	        if (nums.size() == 1) return to_string(nums[0]);

	        if (nums.size() == 2) return to_string(nums[0]) + "/" + to_string(nums[1]);

	        string result = to_string(nums[0]) + "/(";

	        for (int i = 1; i < nums.size(); ++i) {

	            result += to_string(nums[i]);

	            if (i != nums.size() - 1) result += "/";

	        }

	        result += ")";

	        return result;

	    }

	};