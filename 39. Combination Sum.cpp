class Solution {
public:
    vector<vector<int>>v;
    void comb( int ind,int target,vector<int>&temp,vector<int>& can){
        if(ind>=can.size())
            return;
        if(target==0){
            v.push_back(temp);
            return;
        }
        
        //recursive case
        if(can[ind]<=target){
            temp.push_back(can[ind]);
            comb(ind,target-can[ind],temp,can);
            temp.pop_back();
        }
        comb(ind+1,target,temp,can);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>temp;
        comb(0,target,temp,candidates);
        return v;
    }
};
