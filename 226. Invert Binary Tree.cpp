class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL)
            return NULL;
        TreeNode* Newroot = new TreeNode(root->val);
        Newroot ->left = invertTree(root->right);
        Newroot ->right = invertTree(root->left);
        return Newroot;
    }
};
