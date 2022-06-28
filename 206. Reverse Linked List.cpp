class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = NULL;
        ListNode* newnode = NULL;
        while(head!=NULL){
            temp = head->next;
            head->next = newnode;
            newnode = head;
            head = temp;
        }
        return newnode;
    }
};
