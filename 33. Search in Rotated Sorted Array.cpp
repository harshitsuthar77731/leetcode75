class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i = 0;
        int j = nums.size()-1;
        while(i<=j){
            if(nums[i]==target)
                return i;
            if(nums[j]==target)
                return j;
            
            int mid = i+(j-i)/2;
            if(nums[mid]==target)
                return mid;
            
            if(nums[i]>nums[j]){
                if(target>nums[i])
                    j--;
                else if(target<nums[i])
                    i++;
            }
            else{
                if(nums[mid]>target)
                    j = mid-1;
                else
                    i=mid+1;
            }  
        }
        return -1;
    }
};
