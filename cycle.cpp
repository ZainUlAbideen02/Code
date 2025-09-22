/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next){
        return nullptr;
       }

       ListNode * prev = head;
       ListNode * curr = head;

       while(curr && curr->next){
        prev = prev->next;
        curr = curr->next->next;
        if(curr == prev){
            ListNode *ptr1 = head;
            ListNode *ptr2 = prev;
            while (ptr1 != ptr2) {
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            }
            return ptr1;
        }
       }
       return nullptr;
       
    }
};