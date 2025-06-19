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
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*,int>m;
        ListNode* temp = head;
        int cnt = 0;
        while(temp != NULL && temp->next != NULL){
            auto it = m.find(temp); 
            if(it != m.end()){
                return it->first;
            }
            m[temp] = cnt;
            temp = temp->next;
            cnt++;
        }

        return NULL;
    }
};