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
        if(!head){
            return NULL;
        }
        if(!head->next){
            return head;
        }

        int size = 1;

        ListNode * last  = head;

        while(last->next){
            size++;
            last = last->next;
        }

        ListNode * curr = head->next;
        ListNode * prev = head;

        for(int i = 1;i<size;i+=2){
          
          last->next = curr;
          prev->next = curr->next;
          prev = prev->next;
          curr = prev->next;
          last = last->next;
          last->next = NULL;
           
        }

        return head;

    }
};