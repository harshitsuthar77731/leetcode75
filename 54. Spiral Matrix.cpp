class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>v;
        int t = matrix.size()*matrix[0].size();
        int rowu = 0;
        int coll = 0;
        int rowd = matrix.size()-1;
        int colr = matrix[0].size()-1;
        while(coll<=colr&&rowu<=rowd){
            if(v.size()>=t)
                break;
            for(int i=coll;i<=colr;i++){
                v.push_back(matrix[rowu][i]);
            }
            rowu++;
            if(v.size()>=t)
                break;
            for(int i=rowu;i<=rowd;i++){
                v.push_back(matrix[i][colr]);
            }
            colr--;
            if(v.size()>=t)
                break;
            for(int i=colr;i>=coll;i--){
                v.push_back(matrix[rowd][i]);
            }
            rowd--;
            if(v.size()>=t)
                break;
            for(int i=rowd;i>=rowu;i--){
                v.push_back(matrix[i][coll]);
            }
            coll++;
            if(v.size()>=t)
                break;
        }
       
        return v;
    }
};
