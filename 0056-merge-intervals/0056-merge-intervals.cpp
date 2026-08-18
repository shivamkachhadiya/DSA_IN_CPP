class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end());
        vector<vector<int>>ans;
        for(int i=0;i<arr.size();i++){
            if(ans.empty()){
                ans.push_back(arr[i]);
                continue;
            }
            else{
                int take_first_element=arr[i][0];
                int take_second_element=arr[i][1];
                int take_last_ans_element=ans.back()[1];
                if(take_first_element<=take_last_ans_element){
                    ans.back()[1]=max(take_last_ans_element,take_second_element);
                }else{
                    ans.push_back(arr[i]);
                }
            }
        }
        return ans;
    }
};