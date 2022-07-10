class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int,int>mp;
        
        while(n>1){
            if(mp[n]>0)
                return false;
            mp[n]++;
            vector<int>v;
            int t = n;
            while(t>0){
                v.push_back(t%10);
                t = (t-t%10)/10;
            }
            int sum = 0;
            for(int i=0;i<v.size();i++){
                sum+=(v[i]*v[i]);
            }
            n = sum;
        }
        return true;
    }
};
