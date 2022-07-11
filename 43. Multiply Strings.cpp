class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int>v1;
        vector<int>v2;
        for(auto x:num1)
            v1.push_back(x-'0');
         for(auto x:num2)
            v2.push_back(x-'0');
        
        reverse(v1.begin(),v1.end());
        reverse(v2.begin(),v2.end());
        int arr[100000] = {0};
        int ind = 0;
        for(int i=0;i<v2.size();i++){
            int t = v2[i];
            int temp[100000] = {0};
            int carry = 0;
            for(int j=0;j<v1.size();j++){
                int mul = t*v1[j]+carry;
                temp[j+ind] = mul%10;
                carry = (mul- mul%10)/10;
            }
            ind++;
            temp[ind+v1.size()-1] = carry;
            // add
            int car = 0;
            int j = -1;
            for(int i=0;i<=v1.size()+v2.size()+2;i++)
            {
                int tt = arr[i];
                int sum = tt+temp[i]+car;
                arr[i] = sum%10;
                car = (sum-sum%10)/10;
            }
        }
        string ans = "";
        for(int i=0;i<=v1.size()+v2.size()+2;i++){
            ans+=to_string(arr[i]);
        }
        int ind2 = v1.size()+v2.size()+2;
        
        while(true&&ans.size()>1){
            if(ans[ind2]=='0')
             {   
                ans.pop_back();
                ind2--;
             }
            else
                break;
        }
        reverse(ans.begin(),ans.end());
            return ans;
    }
};
