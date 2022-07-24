
class Solution {
public:
    bool fun(TreeNode* p1,TreeNode* p2){
        if(p1==NULL&&p2==NULL)
            return true;
        if(p1==NULL||p2==NULL)
            return false;
        if(p1->val!=p2->val)
            return false;
        
        bool flag1 = fun(p1->left,p2->right);
        bool flag2 = fun(p1->right,p2->left);
        return flag1&&flag2;
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
            return true;
        return fun(root->left,root->right);
    }
};
