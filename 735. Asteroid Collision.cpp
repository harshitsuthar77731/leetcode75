class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        stack<int>st;
        for(int i=0;i<ast.size();i++){
            if(st.size()==0)
                st.push(ast[i]);
            else if(st.size()>0){
                bool flag = true;
                    while(st.size()>0&&(st.top()>0&&ast[i]<0)){
                    flag = false;
                    if(abs(ast[i])>abs(st.top())){
                        st.pop();
                        flag=true;
                        continue;
                    }else if(abs(ast[i])==abs(st.top())){
                        st.pop();
                        break;
                    }else
                        break;
                }
                if(flag)
                    st.push(ast[i]);
            }
        }
        vector<int>v;
        while(st.size()>0)
        {
            v.push_back(st.top());
            st.pop();
        }
        reverse(v.begin(),v.end());
        return v;
    }
};
