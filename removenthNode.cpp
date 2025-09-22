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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int k = 0;
        ListNode * temp = head;
        while(temp){
            k++;
            temp = temp->next;
        }
        if (n == k) {
        ListNode* newHead = head->next;
        delete head;
        return newHead;
        }

        ListNode * curr = head;
        ListNode * prev = NULL;
        for(int i = 0; i<k-n;i++){
            prev = curr;
            curr= curr->next;
        }
            prev->next = curr->next;
            delete curr;

         return head;

    }
};