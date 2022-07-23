class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0;
        int j=0;
        int count = 0;
        unordered_map<char,int>mp;
        while(j<s.size()){
            mp[s[j]]++;
            if(mp[s[j]]>1){
                while(i<=j&&mp[s[j]]>1){
                    mp[s[i]]--;
                    if(mp[s[i]]==0)
                        mp.erase(s[i]);
                    i++;
                }
            }
            else if(count<mp.size())
                    count = mp.size();
            j++;
        }
        return count;
    }
};
