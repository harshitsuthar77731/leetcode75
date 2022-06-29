class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int h = 0;
        ListNode* temp = head ;
        while(temp!=NULL){
            temp = temp->next;
            h++;
        }
        h = h/2;
        while(h--){
            head = head->next;
        }
        return head;
    }
};
