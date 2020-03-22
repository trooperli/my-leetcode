/**
 * This is a elementary school maths while using linked list. One
 * important thing to note is that we need to initiate a head which is
 * precedent to the first node of the linked list, thus everytime we
 * just need to update the next node. The carry in the code represents
 * the carry-over from the previous summation. The code itself is
 * self-explanatory. Be careful about the initialization of pointers.
 */



class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p = new ListNode(0);
        auto p_head = p;
        int carry = 0;
        while (l1 or l2 or carry) {
            int sum = (l1?l1->val:0)+(l2?l2->val:0)+carry;
            carry = sum/10;
            p->next = new ListNode(sum%10);
            p = p->next;
            l1 = l1?l1->next:NULL;
            l2 = l2?l2->next:NULL;
        }
        return p_head->next;

    }
};
