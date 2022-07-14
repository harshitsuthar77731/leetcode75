class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int t = 0;
        unordered_map<string,int>mp;
        unordered_map<string,int>eq;
        
        for(int i=0;i<words.size();i++){
            if(words[i][0]==words[i][1])
                eq[words[i]]++;
            else 
                mp[words[i]]++;
        }
        int count = 0;
        for(int i=0;i<words.size();i++){
                    string t = words[i];
                    reverse(words[i].begin(),words[i].end());
                   if(mp.find(t)!=mp.end()&&mp.find(words[i])!=mp.end()){
                       int minm = min(mp[t],mp[words[i]]);
                       count+=minm*2;
                   }
                  mp.erase(t);
                  mp.erase(words[i]);
        }
        bool flag = true;
        for(auto x : eq){
            if(x.second%2==1&&flag){
                count++;
                flag = false;
            }
            int t = x.second;
            t = t/2;
            if(t>0){
                t = t*2;
                count+=t;
            }
        }
        int ans = count*2;
        return ans;
    }
};
