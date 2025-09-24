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
        ListNode * temp = head;
        int size = 0;

        while(temp){
            size++;
            temp = temp->next;
        }

         ListNode * curr = head;
         ListNode * prev = nullptr;
         ListNode * newhead = NULL;
        ListNode * first = nullptr;
        ListNode * lastGroupEnd = nullptr;

        while(size>=k){
        for(int i = 0; i<k;i++){
            if(i==0){
                first = curr;
            }
            ListNode * nxt = curr->next;
            curr->next  = prev;
            prev = curr;
            curr = nxt;
        }
        if(newhead==NULL){
                newhead = prev;
            }
        if(lastGroupEnd != nullptr){
                lastGroupEnd->next = prev;
            }
         first->next = curr;
         lastGroupEnd = first;
            size -= k;
            prev = nullptr;
        }
        return newhead ? newhead : head;
    }

};