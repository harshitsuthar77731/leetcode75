class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<routes.size();i++){
            for(auto j:routes[i]){
                mp[j].push_back(i);
            }
        }    
        queue<pair<int,int>>q;
        unordered_set<int>visited={source};
        q.push({source,0});
        while(q.size()>0){
            int bus_stop = q.front().first;
            int bus_no = q.front().second;
            if(bus_stop==target)
                return bus_no;
            q.pop();
            
            for(auto x:mp[bus_stop]){
                for(auto next_stop : routes[x])
                {
                    auto it = visited.insert(next_stop);
                    if(it.second) q.push({next_stop,bus_no+1});
                }
                routes[x].clear();
            }
        }
        
        return -1;
     }
};
