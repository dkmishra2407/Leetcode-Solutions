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
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* temp = head;

        while (temp != NULL && temp->next != NULL) {
            if (temp->val == temp->next->val) {
                ListNode* dup = temp->next;
                temp->next = temp->next->next;
                delete dup;
            } else {
                temp = temp->next;
            }
        }

        return head;
    }
};