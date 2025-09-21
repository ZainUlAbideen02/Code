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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* temp = new ListNode(0);
        ListNode* temp1 = head;
        ListNode* temp2= head->next;
         int i = 0 ;

        while(temp1 && temp1->next){
          temp1->next = temp2->next;
          temp->next = temp2;
          temp2->next = temp1;
          if(i==0){
            head = temp->next;
            i++;
          }
          temp = temp1;
          if(temp1->next){
          temp1 = temp1->next;
          }
          if(temp1->next){
          temp2 = temp1->next;
          }
        }
        return head;
    }
};