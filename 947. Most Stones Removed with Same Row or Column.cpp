class Solution {
public:
    int result =0;
    void dfs(int ind,int n,vector<vector<int>>& stones,vector<bool>&visited){
        visited[ind] = true;
        for(int i=0;i<n;i++){
            if(visited[i]==false){
                if(stones[i][0]==stones[ind][0]||stones[i][1]==stones[ind][1])  //either row or col should be equal
                {
                    result++;
                    dfs(i,n,stones,visited);
                }
            }
        }
        
    }
    int removeStones(vector<vector<int>>& stones) {
        vector<bool>visited(stones.size(),false);
        int n = stones.size(); // no. of stones
        for(int i= 0;i<n;i++){
            if(visited[i]==false)
                dfs(i,n,stones,visited);
        }
        return result;
    }
};
