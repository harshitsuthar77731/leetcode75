class Solution {
public:
    int firstBadVersion(int n) {
        int i = 1;
        int j = n;
        int ans = -1;
        while(i<=j){
            int mid = (i+(j-i)/2);
            if(isBadVersion(mid)==true){
                ans = mid;
                j = mid-1;
            }
            else if(isBadVersion(mid)==false){
                i = mid+1;
            }      
        }
        return ans;
    }
};
