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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* tail=head;
        int c=0;
        while(tail){
            tail=tail->next;
            c++;
        }
        int curr=0;
        ListNode* newhead=NULL;
        tail=head;
        ListNode*prev=NULL;
        while(curr+k<=c){
            ListNode* s=tail;
            ListNode* p=NULL,*q=NULL;
            int i=0;
            while(i<k){
                p=q;
                q=tail;
                tail=tail->next;
                q->next=p;
                i++;
            }
            if(newhead==NULL){
                newhead=q;
            }
            else{
                prev->next=q;
            }
            curr+=k;
            prev=s;
        }
        ListNode* end=newhead;
        if(tail){
            prev->next=tail;
        }
        return newhead;
    }
};