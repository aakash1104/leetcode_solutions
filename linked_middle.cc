class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *ptr1 = head;
        ListNode *ptr2 = head;
        while (ptr2 && ptr2->next) {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next->next;
        }
        return ptr1;
    }
};
