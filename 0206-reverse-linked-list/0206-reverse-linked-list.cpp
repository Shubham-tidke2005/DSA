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
    ListNode* reverseList(ListNode* head) {
        // ListNode *temp=head;
        // ListNode *curr=NULL;
        
        // while(temp!=NULL){
        //     ListNode *nx=new ListNode(temp->val);
        //     nx->next=curr;
        //     curr=nx;
        //     temp=temp->next;
        // }return curr;

        ListNode *prev=NULL;
        ListNode *curr=head;
        while(curr!=NULL){
            ListNode *next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }return prev;
    }
};