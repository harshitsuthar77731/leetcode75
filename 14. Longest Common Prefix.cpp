class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int len = INT_MAX;
        for(auto x : strs)
        {
            if(x.size()<len)
                len = x.size();
        }
        string  t = "";
        for(int i=0;i<len;i++){
            for(int j=0;j<strs.size();j++){
                if(strs[0][i]==strs[j][i])
                    continue;
                else
                    return t;
            }
            t+=strs[0][i];
        }
        return t;
    }
};
