class Solution {
public:
    bool isPalindrome(ListNode* head) {
        int len = 0;
        ListNode* temp = head;
        while(temp){
            temp = temp->next;
            len++;
        }
        stack<int> st;
        int n = len/2;
        while(n--){
            st.push(head->val);
            head = head->next;
        }
        if(len%2 != 0) head = head->next;
        while(head){
            int value = st.top();
            st.pop();
            if(head->val != value) return false;
            head = head->next;
        }
        return true;
    }
};