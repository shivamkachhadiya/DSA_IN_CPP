class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();

    //bruteforce
    //     vector<int>pos;
    //     vector<int>neg;
    //     vector<int>tmp;

    //     for(int i=0;i<n;i++){
    //         if(nums[i]<0){
    //             neg.push_back(nums[i]);
    //         }else{
    //             pos.push_back(nums[i]);
    //         }
    //     }

    //    int i = 0, j = 0;
    //     while (i < pos.size() && j < neg.size()) {
    //         tmp.push_back(pos[i]);
    //         i++;
    //         tmp.push_back(neg[j]);
    //         j++;
    //     }
    //     return tmp;

    //optimal
    vector<int>tmp(n,0);
    int pos=0;
    int neg=1;
    for(int i=0;i<n;i++){
        if(nums[i]<0){
            //negative
            tmp[neg]=nums[i];
            neg=neg+2;

        }else{
            //positive
            tmp[pos]=nums[i];
            pos=pos+2;
        }
    }
    return tmp;
        
    }
};