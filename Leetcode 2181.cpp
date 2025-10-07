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
        if(head==NULL){
            return NULL;
        }
        head = head->next;
        ListNode * newhead = nullptr;
        ListNode * tail = NULL;
  
        int sum = 0;

        while(head){
            if(head->val!=0){
                sum+= head->val;
            }else{
                ListNode* newNode = new ListNode(sum);
                sum = 0;
                if(newhead==NULL){
                    newhead = newNode;
                    tail = newNode;
                }else{
                    tail->next = newNode;
                    tail = newNode;
                }

            }
             head = head->next;
        }

        return newhead;

    }
};