/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        std::unordered_set<ListNode*> ht;
        while (headA) {
            ht.emplace(headA);
            headA = headA->next;
        }
        while (headB) {
            if (ht.find(headB) != ht.end())
                return headB;
            headB = headB->next;
        }
        return nullptr;
    }
};
