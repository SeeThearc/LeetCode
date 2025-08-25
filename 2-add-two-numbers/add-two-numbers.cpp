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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* finall=new ListNode();
        ListNode* tempnode=finall;
        int c=0;
        while(l1 && l2){
            int temp = l1->val+l2->val;
            if(c>0){
                temp+=c;
                c=0;
            }
            while(temp>9){
                c+=1;
                temp-=10;
            }
            tempnode->next = new ListNode(temp);
            tempnode = tempnode->next;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1){
            if(c>0){
                l1->val+=c;
                c=0;
            }
            if(l1->val>9){
                c+=1;
                l1->val-=10;
            }
            tempnode->next = new ListNode(l1->val);
            tempnode=tempnode->next;
            l1=l1->next;
        }
        while(l2){
            if(c>0){
                l2->val+=c;
                c=0;
            }
            if(l2->val>9){
                c+=1;
                l2->val-=10;
            }
            tempnode->next = new ListNode(l2->val);
            tempnode=tempnode->next;
            l2=l2->next;
        }
        if(c>0){
            tempnode->next = new ListNode(c);
        }
        return finall->next;
    }
};