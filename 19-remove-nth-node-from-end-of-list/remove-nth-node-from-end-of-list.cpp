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
    void deleteAtHead(ListNode*& head) {
        if (head == NULL)
            return;
        ListNode* temp = head;
        head = head->next;
        return;
    }

    void deleteAtPosition(ListNode*& head, int position) {
        if (head == nullptr || position < 0)
            return;

        if (position == 0) {
            deleteAtHead(head);
            return;
        }

        ListNode* temp = head;

        position--;
        while (position-- && temp->next != nullptr) {
            temp = temp->next;
        }

        ListNode* NodeToDelete = temp->next;
        if (NodeToDelete == nullptr)
            return;
        temp->next = NodeToDelete->next;
        return;
    }

    int length(ListNode* head) {
        int ans = 0;
        ListNode* temp = head;
        while (temp != NULL) {
            ans++;
            temp = temp->next;
        }
        return ans;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL || head->next == NULL) {
            return NULL;
        }

        int ans = length(head);
        int pos = ans - n;
        deleteAtPosition(head, pos);
        return head;
    }
};