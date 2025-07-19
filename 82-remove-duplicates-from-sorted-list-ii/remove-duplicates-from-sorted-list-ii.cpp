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
    ListNode* deleteDuplicates(ListNode* head) {
    // Dummy node to handle head deletions
    ListNode* dummy = new ListNode(-1);
    dummy->next = head;
    ListNode* prev = dummy;
    ListNode* temp = head;

    while (temp != NULL && temp->next != NULL) {
        int cnt = 0;
        while (temp->next != NULL && temp->val == temp->next->val) {
            cnt++;
            ListNode* dup = temp->next;
            temp->next = temp->next->next;
            delete dup;
        }

        if (cnt > 0) {
            ListNode* dup = temp;
            temp = temp->next;
            delete dup;
            prev->next = temp;
        } else {
            prev = temp;
            temp = temp->next;
        }
    }

    return dummy->next;
}

};