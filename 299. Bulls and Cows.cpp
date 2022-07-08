class Solution {
public:
    string getHint(string secret, string guess) {
        int count = 0;
        int count2 = 0;
        unordered_map<char,char>mp,mp2,mp3;
        for(int i=0;i<guess.size();i++){
            if(guess[i]==secret[i]){
                count++;
                guess[i] = '!';
                secret[i] = '~';
            }
            else{
                mp[secret[i]]++;
                mp2[guess[i]]++;
            }
        }
        for(int i=0;i<guess.size();i++){
            if(mp[guess[i]]>0)
                count2+=  min(mp[guess[i]],mp2[guess[i]]) ;
            mp[guess[i]] = 0;
        }
        string t = to_string(count);
        string t2 = to_string(count2);
        string ans = t+"A"+t2+"B";
        return ans;
    }
};
