class cmp{
    public:
    bool operator()(pair<int,string> a,pair<int,string> b){
        if(a.first==b.first){
            return a.second<b.second; // if equal freq than lexiographical order
        }
        else
            return a.first>b.first; // higher frequency first
        
    }
};


class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>mp;
        priority_queue<pair<int,string>,vector<pair<int,string>>,cmp>pqdesc;
        vector<string>v;
        
        for(auto x : words)
            mp[x]++;
        
        for(auto x : mp){
            pqdesc.push({x.second,x.first});
            if(pqdesc.size()>k)
                pqdesc.pop();
        }
        
        while(pqdesc.size()>0){
            v.push_back(pqdesc.top().second);
            pqdesc.pop();
        }
        reverse(v.begin(),v.end());
        return v;
    }
};
