class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        stack<int> st;
        while(head){    
            st.push(head->val);
            if(st.size() == k){ 
                while(st.size()){
                    int value = st.top();
                    st.pop();
                    temp->next = new ListNode(value);
                    temp = temp->next;
                }
            }
            head = head->next;
        }
        vector<int> v;
        while(st.size()){
            v.push_back(st.top());
            st.pop();
        }
        reverse(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            temp->next = new ListNode(v[i]);
            temp = temp->next;
        }
        return dummy->next;
    }
};