class Solution {
public:
    ListNode* reverse(ListNode* head){
        ListNode* nexti = NULL;
        ListNode* prev = NULL;
        ListNode* temp = head;
        while(temp != NULL){
            nexti = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nexti;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return true;
        }

        if(head->next->next == NULL){
            if(head->val == head->next->val){
                return true;
            }
            return false;
        }
        
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        cout<<slow->val<<endl;
        ListNode* temp = reverse(slow);

        while(temp != NULL){
            if(temp->val != head->val){
                return false;
            }
            temp = temp->next;
            head = head->next;
        }

        return true;
    }
};