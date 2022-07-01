class Solution {
public:
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>v;
        if(root==NULL)
            return v;
        
        map<int,vector<int>>mp;
        queue<pair<TreeNode*,int>>q;
        q.push({root,1});
        int temp = 1;
        while(!q.empty()){
            TreeNode* roottemp = q.front().first;
            int level = q.front().second;
            q.pop();
            mp[level].push_back(roottemp->val);
            if(roottemp->left)
                q.push({roottemp->left,level+1});
            if(roottemp->right)
                q.push({roottemp->right,level+1});
        }
        
        for(auto x:mp){
            v.push_back(x.second);
        }
        return v;
    }
};
