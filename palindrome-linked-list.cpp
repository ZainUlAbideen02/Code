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
    bool isPalindrome(ListNode* head) {
         ListNode *  temp = head;
         ListNode * head2 = head;
         int count = 0;

         while(temp){
         count++;
         temp = temp->next;
         }

            ListNode * temp3 = nullptr;
         for(int i = 0 ; i<count/2;i++){
            temp3 = head2;
            head2 = head2->next;
         }
          if (temp3) {
            temp3->next = NULL;
        }


          ListNode * prev = NULL;
          ListNode * curr = head2;

          while (curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
         }


          head2 = prev;

         for(int i = 0;i<count/2;i++){
            if(head->val!=head2->val){
                return 0;
            }
            head = head->next;
            head2 = head2->next;
         }
         return 1;
    }
};