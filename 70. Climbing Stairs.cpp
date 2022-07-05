class Solution {
public:
    int dp[46];
    int fun(int i,int n){
        if(i>n)
            return 0;
        if(i==n)
            return 1;
        if(dp[i]!=-1)
            return dp[i];
        int o = fun(i+1,n);
        int t = fun(i+2,n);
        return dp[i] = o+t;
        
    }
    int climbStairs(int n) {
        memset(dp,-1,sizeof(dp));
        fun(0,n);
        return dp[0];
        for(int i=0)
    }
};
