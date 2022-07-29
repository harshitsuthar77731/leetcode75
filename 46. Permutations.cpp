class Solution {
public:
    vector<vector<int>>v;
    void fun(int ind,vector<int>& nums){
        if(ind==nums.size()-1){
            v.push_back(nums);
            return;
        }
        // recursive case;
        for(int i=ind;i<nums.size();i++){
            swap(nums[ind],nums[i]);
            fun(ind+1,nums);
            // backtrack;
            swap(nums[ind],nums[i]);
        }
    }
        
    vector<vector<int>> permute(vector<int>& nums) {
        fun(0,nums);
        return v;
    }
};
