class Solution {
public:
	int maxProfit(vector<int>& prices) 
	{
        int lowtill=INT_MAX;
        int ans = 0;
        for(int i=0;i<prices.size();i++){
            lowtill = min(prices[i],lowtill);
            ans = max(ans,prices[i]-lowtill);
        }
        return ans;
	}
};
