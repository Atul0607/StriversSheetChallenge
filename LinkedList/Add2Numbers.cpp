class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode();
        ListNode* curr = res;
        int c = 0,x=0,y=0;
        while(l1 || l2 || c){
            int sum = 0;
            if(l1){
                sum+=l1->val;
                l1 = l1->next;
            }
            if(l2){
                sum+=l2->val;
                l2 = l2->next;
            }
            sum+=c;
            c = sum/10;
            ListNode* newNode = new ListNode(sum%10);
            curr->next = newNode;
            curr = curr->next;
        }
        return res->next;
    }
};