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
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode * curr = head;
        ListNode * next = head;

        int value = 0;

        vector<int>st;

        bool flag = false;

        while(curr){
            value = curr->val;
            while(next){
                if(next->val>value){
                    st.push_back(next->val);
                    flag = true;
                    break;
                }
                if(next->next==NULL){
                    st.push_back(0);
                    flag = true;
                }
                next = next->next;
            }
            if(flag==false){
                st.push_back(0);
            }
            curr = curr->next;
            next = curr;
        }

        return st;
    }
};