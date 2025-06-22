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
    ListNode* f(ListNode* head){
        ListNode* fast = head->next;  // Fix here: start fast from head->next
        ListNode* slow = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while(left != NULL && right != NULL){
            if(left->val <= right->val){
                tail->next = left;
                left = left->next;
            } else {
                tail->next = right;
                right = right->next;
            }
            tail = tail->next;
        }

        tail->next = (left != NULL) ? left : right;
        return dummy.next;
    }

    ListNode* mergesort(ListNode* head){
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* middle = f(head);
        ListNode* right = middle->next;
        middle->next = NULL;

        ListNode* left = mergesort(head);
        right = mergesort(right);

        return merge(left, right);
    }

    ListNode* sortList(ListNode* head) {
        return mergesort(head);
    }
};
