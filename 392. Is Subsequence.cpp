// method 1 queue

class Solution {
public:
    bool isSubsequence(string s, string t) {
        queue<char>q;
       for(int i=0;i<s.size();i++){
           q.push(s[i]);
       }
        for(int i=0;i<t.size();i++){
            if(t[i]==q.front())
                q.pop();
        }
        if(q.size()==0)
            return true;
        else
            return false;
    }
};

// method 2 pointer

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0;
        int j=0;
        while(i<s.size()&&j<t.size())
        {
            if(s[i]==t[j])
            {
                i++;
                j++;
                continue;
            }
            j++;
        }
        if(i==s.size())
            return true;
        return false;
    }
};


// method 3 dp
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        
        if(n==0&&m==0)
            return true;
        
        if(m==0)
            return false;
        
        int dp[n+1][m+1];
        
        for(int i=0;i<=n;i++)
            dp[i][0] = 0;
        for(int j=0;j<=m;j++)
            dp[0][j] = 0;
        
        for(int i=1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                if(s[i-1]==t[j-1])
                    dp[i][j] = 1+dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        
        int len = dp[n][m];
        if(len == n ||len == m)
            return true;
        return false;  
    }
};
