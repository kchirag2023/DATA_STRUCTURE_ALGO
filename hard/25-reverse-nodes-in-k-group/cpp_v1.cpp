// Pushed: 2026-10-11 18:19:38 UTC
// Difficulty: Hard
// Runtime: 0 ms
// Memory: 16.6 MB

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head) return nullptr;

        ListNode* tail = head;
        for (int i = 0; i < k; ++i) {
            if (!tail) return head;
            tail = tail->next;
        }

        ListNode* newHead = reverse(head, tail);
        head->next = reverseKGroup(tail, k);
        return newHead;
    }

private:
    ListNode* reverse(ListNode* cur, ListNode* end) {
        ListNode* prev = nullptr;
        while (cur != end) {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
};