class Solution {
public:
    int dp[101][101];
    int fun(int m, int n,int i,int j){
        if(i<0||i>m||j<0||j>n)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        return dp[i][j]=fun(m,n,i,j+1)+fun(m,n,i+1,j); 
    }
    int uniquePaths(int m, int n) {
        memset(dp,-1,sizeof(dp));
        dp[m][n]=1;
        fun(m,n,1,1);
        return dp[1][1];
    }
};
