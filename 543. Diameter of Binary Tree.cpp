/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;
    int fun(TreeNode* root){
        if(root==NULL)
            return 0;
        int lh = fun(root->left);
        int rh = fun(root->right);
        ans = max(lh+rh,ans);
        return max(lh,rh)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        fun(root);
        return ans;
    }
};
