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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }

        ListNode* oddst=NULL;
        ListNode* oddend=NULL;
        ListNode* evenst=NULL;
        ListNode* evenend=NULL;
        ListNode* temp=head;
        bool oddturn=true;
        while(temp!=NULL){
            if(!oddturn){ //even
                if(evenst==NULL){
                    evenst=temp;
                    temp=temp->next;
                    evenst->next=NULL;
                    evenend=evenst;
                }else{
                    evenend->next=temp;
                    temp=temp->next;
                    evenend=evenend->next;
                    evenend->next=NULL;
                }oddturn=true;
            }else{
                if(oddst==NULL){
                    oddst=temp;
                    temp=temp->next;
                    oddst->next=NULL;
                    oddend=oddst;
                }else{
                    oddend->next=temp;
                    temp=temp->next;
                    oddend=oddend->next;
                    oddend->next=NULL;
                }oddturn=false;
            }
        }if(oddst==NULL){
            return evenst;
        }
        oddend->next=evenst;
        return oddst;
    }
};