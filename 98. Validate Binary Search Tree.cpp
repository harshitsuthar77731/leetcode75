class Solution {
public:
    bool flag = true;
    TreeNode* pre = NULL;
    void fun(TreeNode* root){
        if(root==NULL)
            return;
        fun(root->left);
        if(pre!=NULL){
            if(root->val<=pre->val)
                flag = false;
        }
        pre=root;
        fun(root->right);
    }
    bool isValidBST(TreeNode* root) {
        fun(root);
        return flag;
    }
};
