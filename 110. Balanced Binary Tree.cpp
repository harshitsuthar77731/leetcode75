class Solution {
public:
    bool flag = true;
    int fun(TreeNode* root){
        if(root==NULL)
            return 0;
        int lefth = fun(root->left);
        int righth = fun(root->right);
        if(abs(lefth-righth)>1)
            flag= false;
        return (max(lefth,righth)+1);
    }
    bool isBalanced(TreeNode* root) {
        fun(root);
        return flag;
    }
};
