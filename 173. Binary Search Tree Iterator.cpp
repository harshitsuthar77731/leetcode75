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
class BSTIterator {
public:
    TreeNode* node;
    stack<int>st;
    void fun(TreeNode* root){
        if(root==NULL)
            return;
        fun(root->right);
            st.push(root->val);
        fun(root->left);
    }
    BSTIterator(TreeNode* root) {
        node = root;
        fun(root);
    }
    
    int next() {
        int temp = -1;
        if(st.size()>0)
        {
            temp = st.top();
            st.pop();
        }
        return temp;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
