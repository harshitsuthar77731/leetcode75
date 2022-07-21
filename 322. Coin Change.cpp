class Solution {
public:
    int dp[13][10001];
    int fun(vector<int>& coins, int amount,int ind){
        if(amount==0)
            return 0;
        if(amount<0||ind>=coins.size())
            return INT_MAX-1;
        if(dp[ind][amount]!=-1)
            return dp[ind][amount];
        
        //recursive case
        int take=INT_MAX,not_take = INT_MAX;
        if(amount>=coins[ind])
            take = 1+fun(coins,amount-coins[ind],ind);
        not_take = fun(coins,amount,ind+1);
        
        return dp[ind][amount] = min(take,not_take);
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp,-1,sizeof(dp));
        sort(coins.begin(),coins.end());
        reverse(coins.begin(),coins.end());
        int temp = fun(coins,amount,0);
        if(temp==INT_MAX-1)
            return -1;
        return temp;
    }
};
