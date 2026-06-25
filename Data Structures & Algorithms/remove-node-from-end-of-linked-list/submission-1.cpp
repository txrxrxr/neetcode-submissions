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
        // find the (n+1)th node from the end as n1
        // 1st one: head -> will be the n1 we need when n2 reaches the end
        // 2nd one: head + n
        // when 2nd ptr reaches the last node, then reconnect n1 with n1 next next
        ListNode dummy(-1, head);
        ListNode* n1 = &dummy;
        ListNode* n2 = &dummy;
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
        ListNode* nodeToDel = n1->next;
        n1->next = n1->next->next;
        delete nodeToDel;

        return dummy.next;
    }
};
