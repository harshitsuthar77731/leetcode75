class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i=0;i<matrix.size();i++){
            if(target<=matrix[i][matrix[i].size()-1]){
                int  t = 0;
                int j = matrix[i].size()-1;
                while(t<=j){
                    int mid = t+(j-t)/2;
                    if(matrix[i][mid]==target)
                        return true;
                    else if(matrix[i][mid]>target)
                        j=mid-1;
                    else
                        t=mid+1;
                }
            }
            
        }
        return false;
    }
};
