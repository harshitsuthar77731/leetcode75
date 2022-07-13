
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL)
            return head;
        ListNode* end = head;
        int h = 0;
        while(end->next!=NULL)
        {    end = end->next;
            h++;
        }
        ListNode* tempend= end;
        ListNode* temp = head;
        bool flag= false;
        if(h%2==1)
            flag = true;
        h = h/2;
        if(flag)
            h++;
        while(h>0){
            h--;
                ListNode* second = temp->next;
                ListNode* first = temp;
                end->next = second;
                end = end->next;
                first->next = second->next;
                second->next = NULL;
                temp= temp->next;
        }
        
        return head;
    }
};
