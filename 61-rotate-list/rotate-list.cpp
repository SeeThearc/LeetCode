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
        if(!head || !head->next || k==0)return head;
        int n=0;
        ListNode* tail=head;
        ListNode* p=head;
        while(tail){
            tail=tail->next;
            n++;
        }
        k=k%n;
        if(k==0)return head;
        int i=0;
        tail=head;
        while(i<n-k-1){
            tail=tail->next;
            i++;
        }
        ListNode* newhead=tail->next;
        tail->next=NULL;
        tail=newhead;
        while(tail->next!=NULL){
            tail=tail->next;
        }
        tail->next=p;
        return newhead;
    }
};