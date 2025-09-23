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
    void deleteNode(ListNode* node) {

        ListNode * prev = nullptr;
        ListNode * temp = node;

        while(temp->next!=NULL){
          int value = 0;
          value = temp->val;
          temp->val = temp->next->val;
          temp->next->val = value;
          prev = temp;
          temp = temp->next;
        }
        if(temp->next==NULL){
            prev->next = NULL;
            delete temp;
        }

    }
};