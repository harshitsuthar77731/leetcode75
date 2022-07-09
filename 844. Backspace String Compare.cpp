class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int temp = s.size();
        int bs= 0;
        string nt = "";
        for(int i=temp-1;i>=0;i--){
            if(bs==0&&s[i]!='#')
                nt+=s[i];
            else if(s[i]=='#'){
                bs++;
                continue;
            }
            else if(bs>0){
                bs--;
                continue;
            }
        }
        string st = "";
        bs =0 ;
        temp = t.size();
        for(int i=temp-1;i>=0;i--){
            if(bs==0&&t[i]!='#')
                st+=t[i];
            else if(t[i]=='#'){
                bs++;
                continue;
            }
            else if(bs>0){
                bs--;
                continue;
            }
        }
        if(nt==st)
            return true;
        
        return false;
    }
};
