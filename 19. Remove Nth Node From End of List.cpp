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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int h = 0;
        ListNode* temp = head;
        while(temp!=NULL){
            h++;
            temp=temp->next;
        }
        temp = head;
        if(h==n){
            return head->next;
        }
        h = h-n-1;
        while(h>0){
            head=head->next;
            h--;
        }
        head->next = head->next->next;
        return temp;
    }
};
