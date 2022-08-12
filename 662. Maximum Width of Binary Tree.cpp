class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL)
            return 0;
        unsigned long long level = 1;
        queue<pair<pair<TreeNode*,unsigned long long>,unsigned long long>>q;
        q.push({{root,1},1});
        vector<vector<unsigned long long>>test;
        vector<unsigned long long>temp;
        while(q.size()>0){
            TreeNode *node = q.front().first.first;
            unsigned long long lev = q.front().first.second;
            unsigned long long seq = q.front().second;
            q.pop();
            if(level==lev){
                temp.push_back(seq);
            }else{
                test.push_back(temp);
                temp.clear();
                temp.push_back(seq);
                level++;
            }
            if(node->left){
                q.push({{node->left,lev+1},seq*2});
            }
            if(node->right){
                q.push({{node->right,lev+1},seq*2+1});
            }
        }
        test.push_back(temp);
        unsigned long long ans = 0;
        for(auto x: test){
            ans = max(ans,x[x.size()-1]-x[0]+1);
        }
        return ans;
    }
};

     
