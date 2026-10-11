// Pushed: 2026-10-11 18:14:13 UTC
// Difficulty: Medium
// Runtime: 0 ms
// Memory: 15 MB

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *ptr = head, *temp = head;
        for (int i = 0; i < n; i++) ptr = ptr->next;
        
        if (!ptr) return head->next;
        
        while (ptr->next) {
            ptr = ptr->next;
            temp = temp->next;
        }
        temp->next = temp->next->next;
        return head;
    }
};