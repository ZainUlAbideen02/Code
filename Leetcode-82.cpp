class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy; 

        while (head) {
            // check if current node is start of duplicates
            if (head->next && head->val == head->next->val) {
                int dupVal = head->val;
                // skip all nodes with this duplicate value
                while (head && head->val == dupVal) {
                    ListNode* temp = head;
                    head = head->next;
                    delete temp;
                }
                prev->next = head; // unlink duplicate block
            } else {
                prev = head;      // safe unique node
                head = head->next;
            }
        }

        ListNode* ans = dummy->next;
        delete dummy;
        return ans;
    }
};
