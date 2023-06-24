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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || k==0) return head;
        int sz= 0;
        ListNode* temp = head;
        while(temp){
            temp = temp->next;
            sz++;
        }
        k=k%sz;
        if(k==0) return head;
        sz-=k;
        temp = head;
        ListNode* newhead = new ListNode(-101);
        while(--sz && temp){
            temp = temp->next;
        }
        newhead->next = temp->next;
        temp->next=NULL;
        temp = newhead->next;
        while(temp->next){
            temp = temp->next;
        }
        temp->next = head;
        return newhead->next;
    }
};