/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* fun(TreeNode* root, int p, int q)
    {
         if(root==NULL)
            return NULL;
        if(root->val==p||root->val==q)
            return root;
        
        TreeNode* lef = fun(root->left,p,q);
        TreeNode* righ = fun(root->right,p,q);
        if(lef!=NULL&&righ!=NULL)
            return root;
        if(lef!=NULL)
            return lef;
        return righ;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        return fun(root,p->val,q->val);
       
    }
};
