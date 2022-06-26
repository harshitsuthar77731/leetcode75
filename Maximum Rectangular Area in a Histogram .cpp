 long long getMaxArea(long long arr[], int n)
    {
        //next smaller element right side
        stack<int>stright;
        vector<int>right(n,n);      // default size n
        for(int i=0;i<n;i++){
            if(stright.size()==0)
                stright.push(i);
            if(arr[stright.top()]<=arr[i])
                stright.push(i);
            else{
                while(stright.size()>0&&arr[stright.top()]>arr[i]){
                    right[stright.top()] = i;
                    stright.pop();
                }
                stright.push(i);
            }
        }
        //next smaller element left side
        stack<int>stleft; 
        vector<int>left(n,-1);  // default -1;
        for(int i=n-1;i>=0;i--){
            if(stleft.size()==0)
                stleft.push(i);
            if(arr[stleft.top()]<=arr[i])
                stleft.push(i);
            else{
                while(stleft.size()>0&&arr[stleft.top()]>arr[i]){
                    left[stleft.top()] = i;
                    stleft.pop();
                }
                stleft.push(i);
            }
        }
        // for(int i=0;i<n;i++)
        //     cout<<right[i]<<endl;
        long long int ans = 0;
        for(int i=0;i<n;i++){
            long long int breadth = right[i]-left[i]-1;
            long long int length = arr[i];
            ans = max(ans,breadth*length);
        }
        return ans;
        
    }
