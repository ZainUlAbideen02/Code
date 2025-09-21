class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;

        // Ensure list1 starts with smaller node
        if (list1->val > list2->val) {
            ListNode* temp = list1;
            list1 = list2;
            list2 = temp;
        }

        ListNode* head = list1;
        ListNode* last = list1;
        ListNode* current1 = list1->next;
        ListNode* current2 = list2;

        while (current1 && current2) {
            if (current1->val <= current2->val) {
                last->next = current1;
                current1 = current1->next;
            } else {
                last->next = current2;
                current2 = current2->next;
            }
            last = last->next;
        }

        // Attach remaining part
        if (current1) last->next = current1;
        if (current2) last->next = current2;

        return head;
    }
};
