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
    void reorderList(ListNode* head) {
        if(head->next==NULL)return;
        ListNode* slow=head,*fast=head;
        ListNode*p;
        while(fast && fast->next){
            p=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* half = slow;
        p->next=NULL;
        p=NULL;
        ListNode* q=NULL;
        while(slow){
            p=q;
            q=slow;
            slow=slow->next;
            q->next=p;
        }
        ListNode* first=head;
        while(first && q){
            ListNode *fnext=first->next;
            ListNode *snext=q->next;
            first->next=q;
            q->next=fnext;
            first=fnext;
            q=snext;
        }
        if(q){
            first=head;
            while(first->next!=NULL)first=first->next;
            first->next=q;
        }
    }
};