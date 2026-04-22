	class Solution {

	public:

	    int minSteps(int n) {

	        int ans = 0;

	        for (int d = 2; n > 1; ++d) {

	            while (n % d == 0) {

	                ans += d;

	                n /= d;

	            }

	        }

	        return ans;

	    }

	};