class Solution {
public:
    void dfs(int node,unordered_map<int,vector<int>>&mp,vector<bool>&visited){
        visited[node] = true;
        for(auto x:mp[node]){
            if(visited[x]==false)
                dfs(x,mp,visited);
        }
    }
    int findCircleNum(vector<vector<int>>& isCo) {
        int count = 0;
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<isCo.size();i++){
            for(int j=0;j<isCo[i].size();j++){
                if(i==j)
                    continue;
                if(isCo[i][j]==1)
                    mp[i].push_back(j);
            }
        }
        vector<bool>visited(isCo.size(),false);
        for(int i=0;i<isCo.size();i++){
            if(visited[i]==false){
                count++;
                dfs(i,mp,visited);
            }
        }
        
        return count;
    }
};
