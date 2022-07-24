// method1
 class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL)
            return {};
        queue<pair<TreeNode*,int>>q;
        vector<int>v;
        map<int,int>mp;
        q.push({root,0});
        int temp = 0;
        while(q.size()>0){
            TreeNode* node = q.front().first;
            int level = q.front().second;
            q.pop();
            mp[level] = node->val;
            if(node->left)
                q.push({node->left,level+1});
            if(node->right)
                q.push({node->right,level+1});   
        }
       for(auto x:mp)
           v.push_back(x.second);
        return v;
    }
};
//method2
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL)
            return {};
        queue<pair<TreeNode*,int>>q;
        vector<int>v;
        map<int,int>mp;
        q.push({root,1});
        int temp = 1;
        while(q.size()>0){
            TreeNode* node = q.front().first;
            int level = q.front().second;
            q.pop();
            if(node->left)
                q.push({node->left,level+1});
            if(node->right)
                q.push({node->right,level+1});   
            if(temp!=q.front().second){
                v.push_back(node->val);
                temp++;
            }
        }
       
        return v;
    }
};

