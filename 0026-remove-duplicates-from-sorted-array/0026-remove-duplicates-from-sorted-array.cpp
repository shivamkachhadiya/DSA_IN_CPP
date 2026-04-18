class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int uniqueElements=1;
        //int cm=1;
        int officer=0;
        int n=nums.size();
       for(int cm=1;cm<n;cm++){
            if(nums[cm]!=nums[cm-1]){
                //pichhe vale ke barabar nahi hei
                nums[officer+1]=nums[cm];
                officer++;
                uniqueElements++;
            }
        }
        return uniqueElements;
    }
};