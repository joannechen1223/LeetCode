/*
* Author: joannechen1223
* Date: 2021.01.07
*/


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL)   return head;
        ListNode* pre = NULL;
        ListNode* current = head;
        int cnt = 1;
        while (current->next) {
            if (current->next->val == current->val) {
                cnt ++;
            } else if (cnt == 1) {
                pre = current;
            } else {
                cnt = 1;
                if (!pre)   head = current->next;
                else    pre->next = current->next;
            }
            current = current->next;
        }
        
        if (cnt != 1) {
            if (!pre)   head = current->next;
            else    pre->next = current->next;
        }
        return head;
    }
};