class Solution {
public:
    
    int calculate(string s) {
        stack<char>st;
        string maxm = "2147483647";
        for(int i=0;i<s.size();i++){
            if(s[i]==' ')
                continue;
            if(st.size()>0&&(st.top()=='*'||st.top()=='/')){
                string temp = "";
                string val = "";
                char op = st.top();
                st.pop();
                while(s[i]>='0'&&s[i]<='9')
                    temp+=s[i++];
                while(st.size()>0&&st.top()>='0'&&st.top()<='9')
                {
                    val+=st.top();
                    st.pop();
                }
                reverse(val.begin(),val.end());
                int cal;
                if(op == '*')
                    cal = stoi(val)*stoi(temp);
                else
                    cal = stoi(val)/stoi(temp);
                
                string temp2 = to_string(cal);
                // reverse(temp2.begin(),temp2.end());
                for(int i=0;i<temp2.size();i++){
                    st.push(temp2[i]);
                } 
            }
                st.push(s[i]);
        }
        vector<int>v;
        string temp ="";
        while(st.size()>0){
            if(st.top()>='0'&&st.top()<='9'){
                temp+=st.top();
                st.pop();
            }
            else if(st.top()=='+'||st.top()=='-'){
                int t = 0;
                reverse(temp.begin(),temp.end());
                if(temp==maxm)
                    t = INT_MAX;
                else
                    t = stoi(temp);
                    
                if(st.top()=='-')
                    t*=-1;
                v.push_back(t);
                st.pop();
                temp = "";
            }else
                st.pop();
         }
        reverse(temp.begin(),temp.end());
        if(temp==maxm)
            v.push_back(INT_MAX);
        else
            v.push_back(stoi(temp));
        int ans = 0;
        for(auto x:v)
            ans+=x;       
        return ans;
    }
};
