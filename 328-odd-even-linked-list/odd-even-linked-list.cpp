class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* temp1 = head;
        ListNode* temp2 = head->next;
        ListNode* evenhead = head->next;

        while(temp2 != NULL && temp2->next != NULL){
            temp1->next = temp2->next;       // Link current odd node to next odd
            temp1 = temp1->next;             // Move temp1 forward
            temp2->next = temp1->next;       // Link current even node to next even
            temp2 = temp2->next;             // Move temp2 forward
        }

        temp1->next = evenhead;
        return head;
    }
};