/**
 * This solution is using a fast pointer and slow pointer, while fast
 * moves twice as fast as slow. When fast reaches the end, slow
 * reaches the middle.
 */



class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != NULL and fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
