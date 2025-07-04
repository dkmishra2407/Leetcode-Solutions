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
    ListNode* deleteMiddle(ListNode* head) {

        if(head->next == NULL || head == NULL){
            return NULL;
        }
        ListNode* slow = head;
        ListNode* prev = NULL;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL){
            
            prev = slow;
            slow = slow->next;
            
            fast = fast->next->next;
        }

        ListNode* temp = head;
        ListNode* NodeToDelete = slow;
        if(NodeToDelete == nullptr) return temp;
        prev->next = NodeToDelete->next;
        return head;
    }
};