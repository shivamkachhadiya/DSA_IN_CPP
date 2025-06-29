class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        // int n = nums.size();
        // int j = 0; // Points to the position where the next non-zero element should go

        // // Move all non-zero elements to the front
        // for (int i = 0; i < n; i++)
        // {
        //     if (nums[i] != 0)
        //     {
        //         nums[j] = nums[i];
        //         j++;
        //     }
        // }

        // // Fill the rest of the array with 0s
        // while (j < n)
        // {
        //     nums[j] = 0;
        //     j++;
        // }
        //-----------------------------------------------------------
        int n=nums.size();
	vector<int>tmp;
	int count=0;
	for(int i=0;i<n;i++){
		if(nums[i]!=0){
			tmp.push_back(nums[i]);
			
		}else{
			count++;
		}

	}
	int j=0;
	while(j<count){
		tmp.push_back(0);
		j++;
	}
	nums=tmp;
    }
};