// no tle
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>mp;
        int ans = 0;
        for(auto x : tasks){   
            mp[x]++;
            ans = max(ans,mp[x]);
        }
        int freq= 0;
        for(auto x : mp){
            if(x.second==ans)
                freq++;
        }
        int count = (n+1)*(ans-1)+freq;
        if(count<tasks.size())
            return tasks.size();
        return count;
    }
};

// tle
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>mp;
        for(auto x : tasks)
            mp[x]++;
        priority_queue<pair<int,int>>pq;
        for(auto x : mp)
            pq.push({0,x.second});
        int count = 0;
        while(pq.size()>0){
            int t = pq.top().first;
            int q = pq.top().second;
            // cout<<t<<" "<<q<<endl;
            
            if(t==0)
           {     
                q--;
                t = -n;
           }
            else
                t++;
            pq.pop();
            vector<pair<int,int>>vp;
            while(pq.size()>0){
                int time = pq.top().first;
                int quantity = pq.top().second;
                if(time<0)
                    time++;
                pq.pop();
                vp.push_back({time,quantity});
            }
            for(auto x : vp){
                pq.push(x);
            }
            if(q>0){
                pq.push({t,q});
            }
            count++;
        }
        return count;
    }
};
