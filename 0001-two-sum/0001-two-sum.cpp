class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
      int n=arr.size();
      unordered_map<int,int>m;

      vector<int>ans;
      for(int i=0;i<n;i++){
        int fisrt=arr[i];
        int sec=target-fisrt;
        if(m.find(sec)!=m.end()){
            ans.push_back(i);
            ans.push_back(m[sec]);
            break;

        }
        m[fisrt]=i;
      }
      return ans;

    
    }
};