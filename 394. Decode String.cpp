class Solution {
public:
    string decodeString(string s) {
        stack<char>st;
        for(auto x : s){
            if(x!=']'){
                st.push(x);
            }
            else{
                string t = "";
                while(st.top()!='['){
                    t+=st.top();
                    st.pop();
                }
                reverse(t.begin(),t.end());
                st.pop();
                string num = "";
                while(!st.empty()&&isdigit(st.top()))
                {
                    num+=st.top();
                    st.pop();
                }
                reverse(num.begin(),num.end());
                int n=stoi(num);
                while(n--){
                   for(auto c:t)
                       st.push(c);
                }
            }
        }
        string ans = "";
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
