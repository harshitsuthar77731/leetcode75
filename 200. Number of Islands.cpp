class Solution {
public:
    void fun(vector<vector<char>>& grid,int i,int j,int r,int c){
        if(i<0||i>=r||j<0||j>=c||grid[i][j]=='0'||grid[i][j]=='2')
            return;
        grid[i][j] = '2';
        fun(grid,i+1,j,r,c);
        fun(grid,i,j+1,r,c);
        fun(grid,i,j-1,r,c);
        fun(grid,i-1,j,r,c);
    }
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    count++;
                    fun(grid,i,j,grid.size(),grid[0].size());
                }
            }
        }
        return count;
    }
};
