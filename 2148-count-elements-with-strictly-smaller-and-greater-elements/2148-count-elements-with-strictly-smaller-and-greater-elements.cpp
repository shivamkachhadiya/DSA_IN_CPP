class Solution {
public:
    int countElements(vector<int>& arr) {
       int count=0;
       int mini=*min_element(arr.begin(),arr.end());
       int maxi=*max_element(arr.begin(),arr.end());
       for(auto &i:arr){
        if(i>mini&&i<maxi){
            count++;
        }
       }
       return count;
    }
};