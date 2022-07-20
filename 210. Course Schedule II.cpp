class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        if(n>0&&pre.size()==0)
        {
            vector<int>ans;
            for(int i=0;i<n;i++)
                ans.push_back(i);
            return ans;
        }
        map<int,vector<int>>mp;
        for(auto x:pre)
            mp[x[1]].push_back(x[0]);
        
        // indegree
        int *indegree= new int[n];
        for(int i=0;i<n;i++){
            indegree[i] = 0;
        }
        for(int i=0;i<n;i++){
            for(auto v:mp[i])
                indegree[v]++;
        }
            vector<int>v;
            queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0)
                q.push(i);
        }
            
            while(q.size()>0){
                int t =q.front();
                q.pop();
                v.push_back(t);
                    for(auto i:mp[t]){
                        indegree[i]--;
                        if(indegree[i]==0)
                            q.push(i);
                    }
            }
            if(v.size()==n)
                return v;
        return {};
    }
};
