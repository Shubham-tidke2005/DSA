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
   
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL || left == right)
            return head;

        ListNode* curr = head;
        ListNode* prevLeft = NULL;

        // Move to left position
        for(int i = 1; i < left; i++) {
            prevLeft = curr;
            curr = curr->next;
        }

        ListNode* tail = curr;
        ListNode* prev = NULL;

        // Reverse right-left+1 nodes
        for(int i = 0; i <= right-left; i++) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // Connect first half
        if(prevLeft != NULL)
            prevLeft->next = prev;
        else
            head = prev;

        // Connect second half
        tail->next = curr;

        return head;
    }
};