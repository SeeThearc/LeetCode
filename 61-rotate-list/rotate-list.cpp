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
        if(!head || !head->next)return head;
        int c=0;
        ListNode*cnode=head;
        while(cnode){
            c++;
            cnode=cnode->next;
        }
        k=k%c;
        for(int i=0;i<k;i++){
            ListNode* temp = head;
            ListNode* q;
            while(temp->next){
                q=temp;
                temp=temp->next;
            }
            q->next=NULL;
            temp->next=head;
            head=temp;
        }
        return head;
    }
};