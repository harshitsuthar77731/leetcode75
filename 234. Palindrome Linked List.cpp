/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool flag=true;
    void fun(ListNode* head,ListNode*& init){
        if(head==NULL)
            return;
        
        fun(head->next,init);
        
        if(init->val!=head->val)
             flag = false;
        
        init = init->next;
    }
    bool isPalindrome(ListNode* head) {
        fun(head,head);
        return flag;
    }
};
