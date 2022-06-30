class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        int count = 0;
        int t = 0;
        for(auto x : mp){
            int temp = x.second;
            if(temp%2==1){
                count+=(temp-1);
                t = 1;
            }
            else{
                count+=temp;
            }
        }
        return count+t;
    }
};
