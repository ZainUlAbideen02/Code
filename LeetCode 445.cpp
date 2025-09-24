class Solution {
public:
    ListNode* reverse(ListNode* l1) {
        ListNode* prev = nullptr;
        ListNode* curr = l1;

        while (curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = reverse(l1);
        ListNode* temp2 = reverse(l2);
        ListNode* head = nullptr;
        ListNode* prev = nullptr;
        int carry = 0;

        while (temp1 || temp2 || carry) {
            int x = (temp1 ? temp1->val : 0);
            int y = (temp2 ? temp2->val : 0);
            int sum = carry + x + y;

            carry = sum / 10;
            int digit = sum % 10;

            ListNode* temp = new ListNode(digit);

            if (!head) {
                head = temp;
                prev = head;
            } else {
                prev->next = temp;
                prev = temp;
            }

            if (temp1) temp1 = temp1->next;
            if (temp2) temp2 = temp2->next;
        }

        return reverse(head);
    }
};
