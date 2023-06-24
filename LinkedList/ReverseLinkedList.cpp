class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head,*prev = NULL,*store = NULL;
        while(curr){
            store = curr->next;
            curr->next = prev;
            prev = curr;
            curr = store;
        }
        return prev;
    }
};