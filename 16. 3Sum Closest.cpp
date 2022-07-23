class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int ans = INT_MAX;
        for(int i=0;i<nums.size()-2;i++){
            int left = i+1;
            int right = nums.size()-1;
            while(left<right){
                int netsum = nums[i]+nums[left]+nums[right];
                if(ans==INT_MAX)
                        ans= netsum;
                else if(abs(target-netsum)<abs(target-ans))
                        ans = netsum;   
                if(netsum>target){
                    right--;
                }
                else if(netsum<target){
                    left++;
                }
                else 
                    break;
            }
        }
        return ans;
    }
};
