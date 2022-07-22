class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxr = INT_MIN;
        int maxl = INT_MIN;
        int curr = 1;
        for(int i=0;i<nums.size();i++){
            curr*=nums[i];
            maxr = max(maxr,curr);
            if(curr==0)
                curr= 1;
        }
        curr=1;
         for(int i=nums.size()-1;i>=0;i--){
            curr*=nums[i];
            maxl = max(maxl,curr);
            if(curr==0)
                curr= 1;
        }
        return max(maxr,maxl);
    }
};
