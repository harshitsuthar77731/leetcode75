class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>v;
        int i = 0;
        int j = 0;
        unordered_map<char,int>mp,test;
        int count = 0;
        for(auto x : p)
            mp[x]++;
        while(j<s.size()){
            test[s[j]]++;
            if(j-i+1>p.size()){
                while(j-i+1>p.size()){
                    test[s[i]]--;
                    if(test[s[i]]==0)
                        test.erase(s[i]);
                    i++;
                 }
            }
            if(test==mp)
                v.push_back(i); 
            j++;
        }
        return v;
    }
};

///////////// improved tc
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>v;
        int i = 0;
        int j = 0;
        unordered_map<char,int>mp;
        int count = 0;
        for(auto x : p)
            mp[x]++;
        count = mp.size();
        // int ans = 0;
        while(j<s.size()){

            if(mp.find(s[j])!=mp.end()){
                mp[s[j]]--;
                if(mp[s[j]]==0)
                    count--;
            }
            
            if(j-i+1==p.size()){
                if(count == 0)
                    v.push_back(i);
                    if(mp.find(s[i])!=mp.end())
                    {    
                        if(mp[s[i]]==0)
                            count++;
                        mp[s[i]]++;
                    }
                    i++;
            }
            j++;
        }
        return v;
    }
};
