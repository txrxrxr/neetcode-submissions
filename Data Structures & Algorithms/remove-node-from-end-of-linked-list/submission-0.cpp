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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 2 pointers
        // 1st one: head
        // 2nd one: head + n
        // when 2nd ptr reaches the last node, then reconnect node 1 and node 2
        ListNode* dummy = new ListNode(-1, head);
        ListNode* n1 = dummy;
        ListNode* n2 = dummy;
        int i = 0;
        while (i < n) {
            n2 = n2->next;
            ++i;
        }

        while (n2->next) {
            n2 = n2->next;
            n1 = n1->next;
        }

        // join n1 -> n2
        n1->next = n1->next->next;

        return dummy->next;
    }
};
