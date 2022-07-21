class Solution {
public:
    int rob(vector<int>& nums) {
        int dp[1001] = {0};
        dp[1] = nums[0];
        for(int i=2;i<=nums.size();i++){
            dp[i] = max(dp[i-1],dp[i-2]+nums[i-1]);
        }
        return dp[nums.size()];
    }
};
