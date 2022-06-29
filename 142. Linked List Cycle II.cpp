class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
         ListNode* slow = head;
        ListNode* fast = head;
        bool flag=true;
        while(fast!=NULL&&fast->next!=NULL){
            slow= slow->next;
            fast = fast->next->next;
            if(fast==slow)
             {  flag =false;
                break;
             }
        }
        if(fast==NULL||flag)
            return NULL;
        slow = head;
        while(slow!=fast){
            slow = slow->next;
            fast=fast->next;
        }
        
        return fast;
    }
};
