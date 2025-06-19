/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        if(head == NULL ||head->next == NULL){
            return false;
        }

        unordered_map<ListNode*,int>s;
        ListNode* temp = head;
        while(temp != NULL){
            if(s.find(temp) != s.end()){
                return true;
            }
            s[temp] = 1;
            temp = temp->next;
        }

        return false;
    }
};