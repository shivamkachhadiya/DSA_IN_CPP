class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int lp=0,rp=n-1,ans=0,maxwidth=0;
        while(lp<rp){
            int width=rp-lp;
            int currheight=min(height[lp],height[rp]);
            int currwidth=width*currheight;
            maxwidth=max(maxwidth,currwidth);
            if(height[lp]<height[rp]){
                lp++;
            }else{
                rp-- ;
            }
        }
        return maxwidth;
    }
};