class Solution {
public:
    vector<int>v;
    void fun(Node* root){
        if(root==NULL)
            return ;
        v.push_back(root->val);
        for(auto x : root->children){
            fun(x);
        }

    }
    vector<int> preorder(Node* root) {
        fun(root);
        return v;
    }
};
