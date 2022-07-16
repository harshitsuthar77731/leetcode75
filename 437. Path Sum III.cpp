class Solution {
public:
    int count = 0;
    void sum(TreeNode* root,int target,int current){
        if(root==NULL)
            return;
        
        if(root->val>0&&(current>INT_MAX-root->val))
            return;
        current = current+root->val;
        if(target==current)
            count++;
        sum(root->left,target,current);
        sum(root->right,target,current);
        
    }
    void path(TreeNode* root,int targetSum){
        if(root==NULL)
            return;
        sum(root,targetSum,0);
        path(root->left,targetSum);
        path(root->right,targetSum);
    }
    int pathSum(TreeNode* root, int targetSum) {
        path(root,targetSum);
        return count;
    }
};
