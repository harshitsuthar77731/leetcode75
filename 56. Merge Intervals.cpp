class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& in) {
        stack<int>st;
        sort(in.begin(),in.end());
        for(int i=0;i<in.size();i++){
            if(st.empty())
            {   st.push(in[i][0]);
                st.push(in[i][1]);
            }else{
                int pre = st.top();
                st.pop();
                int currf = in[i][0];
                int currs = in[i][1];
                
                if(pre>currs){
                    st.push(pre);
                    continue;
                }
                else if(pre>=currf)
                    st.push(currs);
                else{
                    st.push(pre);
                    st.push(currf);
                    st.push(currs);
                }
            }
            
        }
        vector<vector<int>>v;
            while(st.size()>0){
                int t= st.top();
                st.pop();
                int p = st.top();
                st.pop();
                v.push_back({p,t});
            }
        sort(v.begin(),v.end());
        return v;
    }
};
