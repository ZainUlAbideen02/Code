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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) {
            return nullptr;
        }

        ListNode* temp1 = headA;

        while (temp1) {  // outer loop
            ListNode* temp2 = headB;
            while (temp2) {  // inner loop
                if (temp1 == temp2) {  // check node itself
                    return temp1;  // intersection found
                }
                temp2 = temp2->next;
            }
            temp1 = temp1->next;
        }

        return nullptr;  // no intersection
    }
};
