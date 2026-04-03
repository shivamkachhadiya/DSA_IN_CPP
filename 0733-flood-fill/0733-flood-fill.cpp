class Solution {
public:
void dfs(vector<vector<int>>& image, int i, int j, int newColor,
        int orgColor) {
            if(i<0||j<0||i>=image.size()||j>=image[0].size()||
                image[i][j]==newColor || image[i][j]!=orgColor){
                    return;
                }
            image[i][j]=newColor;
            dfs(image,i-1,j,newColor,orgColor);
            dfs(image,i,j+1,newColor,orgColor);
            dfs(image,i+1,j,newColor,orgColor);
            dfs(image,i,j-1,newColor,orgColor);
            

}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
         dfs(image,sr,sc,color,image[sr][sc]);
        return image;
    }
};