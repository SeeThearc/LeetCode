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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head || !head->next && n==1)return nullptr;
        int c=0;
        ListNode*temp=head;
        while(temp){
            temp=temp->next;
            c++;
        }
        int f = c-n+1;
        int fc=1;
        if(f==1)return head->next;
        temp=head;
        ListNode* q=head;
        while(temp){
            if(fc==f){
                q->next=temp->next;
                break;
            }
            q=temp;
            temp=temp->next;
            fc++;
        }
        return head;
    }
};