class Solution {
public:
    int pivotIndex(vector<int>& arr) {
        // int i =0;
        int temp =  accumulate(arr.begin(),arr.end(),0);
        int sum = 0;
       for(int i=0;i<arr.size();i++){
           if((temp-arr[i])%2==0&&(temp-arr[i])/2==sum)
               return i;
           sum+=arr[i];
       }
        return -1;
    }
};
