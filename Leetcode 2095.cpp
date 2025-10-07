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
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return NULL;
        }
        ListNode * temp = head;
        int size = 0;
        while(temp){
            size++;
            temp = temp->next;
        }

        int len = (size/2);
        ListNode * prev = NULL;
        ListNode * curr = head;

        for(int i = 0;i<len;i++){
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;
        delete curr;


        return head;

    }
};