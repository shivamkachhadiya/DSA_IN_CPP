
class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int prod = 1;
        int maxiProd = INT_MIN;

        for (int i = 0; i < arr.size(); i++) {
            prod *= arr[i];
            maxiProd = max(maxiProd, prod);

            if (arr[i] == 0)
                prod = 1;
        }

        int newProd = 1;

        for (int i = arr.size() - 1; i >= 0; i--) {
            newProd *= arr[i];
            maxiProd = max(maxiProd, newProd);

            if (arr[i] == 0)
                newProd = 1;
        }

        return maxiProd;
    }
};
