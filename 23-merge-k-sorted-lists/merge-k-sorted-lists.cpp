struct cmp {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val; 
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;

        for (auto node : lists) {
            if (node) pq.push(node);
        }

        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        while (!pq.empty()) {
            ListNode* top = pq.top();
            pq.pop();

            curr->next = top;
            curr = curr->next;

            if (top->next) {
                pq.push(top->next);
            }
        }

        return dummy->next;
    }
};
