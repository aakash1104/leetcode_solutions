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
    ListNode* reverseList(ListNode* head) {
        if (!head)
            return nullptr;

        ListNode *prev = nullptr;
        ListNode *p, *q;

        p = q = head;

        while (p->next) {
            p = p->next;
            q->next = prev;
            prev = q;
            q = p;
        }

        p->next = prev;
        head = p;

        return head;
    }
};
