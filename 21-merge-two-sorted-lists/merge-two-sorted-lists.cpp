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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL && list2==NULL)return NULL;
        else if(list1==NULL)return list2;
        else if(list2==NULL)return list1;
        ListNode* final = NULL;
        if(list1->val<=list2->val){
            final = list1;
            list1=list1->next;
        }
        else{
            final=list2;
            list2=list2->next;
        }
        ListNode * tail = final;
        while(list1 && list2){
            if(list1->val<list2->val){
                ListNode* newnode = new ListNode(list1->val);
                tail->next=newnode;
                tail=tail->next;
                list1=list1->next;
            }
            else{
                ListNode* newnode = new ListNode(list2->val);
                tail->next=newnode;
                tail=tail->next;
                list2=list2->next;
            }
        }
        while(list1){
            ListNode* newnode = new ListNode(list1->val);
            tail->next=newnode;
            tail=tail->next;
            list1=list1->next;
        }
        while(list2){
            ListNode* newnode = new ListNode(list2->val);
            tail->next=newnode;
            tail=tail->next;
            list2=list2->next;
        }
        return final;
    }
};