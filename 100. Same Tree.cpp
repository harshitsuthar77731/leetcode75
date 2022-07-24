public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL&&q==NULL)
            return true;
        else if(p==NULL||q==NULL)
            return false;
        if(p->val!=q->val)
            return false;
        bool flag1 = isSameTree(p->right,q->right);
        bool flag2 = isSameTree(p->left,q->left);
        return flag1&&flag2;
    }
};
