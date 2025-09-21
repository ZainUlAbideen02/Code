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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * temp1 = l1;
        ListNode * temp2 = l2;
        ListNode * head = NULL;
        ListNode * temp3;
        int carry = 0;

        while (temp1 || temp2) {
            int x = (temp1 ? temp1->val : 0);
            int y = (temp2 ? temp2->val : 0);
            int sum = x + y + carry;

            if (sum < 10) {
                carry = 0;
                ListNode * temp = new ListNode(sum);
                if (head == NULL) {
                    head = temp;
                    temp3 = temp;
                } else {
                    temp3->next = temp;
                    temp3 = temp;
                }
            } else {
                int remainder = sum % 10;
                ListNode * temp = new ListNode(remainder);
                carry = 1;
                if (head == NULL) {
                    head = temp;
                    temp3 = temp;
                } else {
                    temp3->next = temp;
                    temp3 = temp;
                }
            }

            temp1 = (temp1 ? temp1->next : nullptr);
            temp2 = (temp2 ? temp2->next : nullptr);
        }

        if (carry > 0) {
            ListNode * temp = new ListNode(carry);
            temp3->next = temp;
        }

        return head;
    }
};
