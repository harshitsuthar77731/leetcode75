class Solution {
public:
    void grid(vector<vector<int>>& image, int sr, int sc,int m,int n, int color,int sp){
        if(sr<0||sr>=m||sc<0||sc>=n||image[sr][sc]==color||image[sr][sc]!=sp)
            return;
            image[sr][sc]=color;
            grid(image,sr+1,sc,m,n,color,sp);
            grid(image,sr,sc+1,m,n,color,sp);
            grid(image,sr-1,sc,m,n,color,sp);
            grid(image,sr,sc-1,m,n,color,sp);
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        grid(image,sr,sc,image.size(),image[0].size(),color,image[sr][sc]);
        return image;
        
    }
};
