class Solution {
public:
    string minWindow(string t, string p) {
        unordered_map<char,int>mp;
        for(int i=0;i<p.size();i++)
            mp[p[i]]++;
        int count = mp.size();
        int indexi;
        int minm = INT_MAX;
        int i = 0;
        int j = 0;
        
        while(j<t.size())
        {
                if(mp.find(t[j])!=mp.end())
                {
                    mp[t[j]]--;
                    if(mp[t[j]]==0)
                        count--;
                }
            
                if(count == 0)
                {
                    if(minm>(j-i+1))
                    { minm =j-i+1; indexi = i;}
                    
                    while(count==0)
                    {
                        if(mp.find(t[i])!=mp.end())
                        {
                            mp[t[i]]++;
                            if(mp[t[i]]>0)
                                count++;
                            
                            if(minm>(j-i+1))
                            {
                                minm =j-i+1;
                                indexi = i;
                            }
                        }
                        i++;
                    }
                }
        j++;
            
    }
        return (minm==INT_MAX)?"":t.substr(indexi,minm);
        
    }
};
