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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp=head;
        ListNode* st=head;
        ListNode* prev_of_st=NULL;
        if(temp==NULL || (temp->next==NULL && temp->val==0)){
            return NULL;
        }

        int sum=0;
        while(temp!=NULL){
            if(temp->val==0){
                if(sum!=0){
                    st->val=sum;
                    prev_of_st=st;
                    st=st->next;
                    sum=0;
                }
            }
            sum+=temp->val;
            temp=temp->next;
        }

        if(prev_of_st!=NULL){
            prev_of_st->next=NULL;
        }
        return head;
    }
};