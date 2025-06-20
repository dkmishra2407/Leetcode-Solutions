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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL && l2 == NULL){
            return NULL;
        }
        if(l1 == NULL){
            return l2;
        }
        if(l2 == NULL){
            return l1;
        }

        int hacha = 0;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;

        ListNode* ans = new ListNode(-1); 
        ListNode* tail = ans; 

        while(temp1 != NULL && temp2 != NULL){
            int sum = temp1->val + temp2->val + hacha;
            ListNode* newNode = new ListNode(sum % 10);
            tail->next = newNode;
            tail = tail->next;
            hacha = sum / 10;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        while(temp1 != NULL){
            int sum = temp1->val + hacha;
            ListNode* newNode = new ListNode(sum % 10);
            tail->next = newNode;
            tail = tail->next;
            hacha = sum / 10;
            temp1 = temp1->next;
        }

        while(temp2 != NULL){
            int sum = temp2->val + hacha;
            ListNode* newNode = new ListNode(sum % 10);
            tail->next = newNode;
            tail = tail->next;
            hacha = sum / 10;
            temp2 = temp2->next;
        }

        if(hacha > 0){
            ListNode* newNode = new ListNode(hacha);
            tail->next = newNode;
        }

        return ans->next;
    }
};
