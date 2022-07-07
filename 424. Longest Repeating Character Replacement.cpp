class Solution {
public:
    int characterReplacement(string s, int k) {
        int i = 0;
        int j = 0;
        int ans = 0;
        unordered_map<char,int>mp;
        while(j<s.size()){
            mp[s[j]]++;
          
            int tt = 0;
            int sum = 0;
            for(auto x:mp){
                tt=max(tt,x.second);
                sum+=x.second;
            }
            if(sum-tt>k&&mp.size()>1){
            while(i<=j){
                mp[s[i]]--;
                if(s[i]==0)
                    mp.erase(s[i]);
                int t1 = 0;
                int sum1 = 0;
                for(auto x:mp){
                    t1 = max(t1,x.second);
                    sum1+=x.second;
                }

                i++;
                if(sum1-t1<=k||mp.size()<2)
                    break;
            }
            }
                int temp = 0;
                  for(auto x:mp)
                    temp+=x.second;
                if(temp>ans)
                    ans = temp;
                j++;
        }
        return ans;
    }
};
