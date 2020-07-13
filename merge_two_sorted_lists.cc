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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = nullptr;
        ListNode *tail = nullptr;

        while (l1 && l2) {
            ListNode *temp;
            if (l1->val <= l2->val) {
                temp = new ListNode(l1->val);
                l1 = l1->next;
            } else {
                temp = new ListNode(l2->val);
                l2 = l2->next;
            }
            if (!head) {
                head = temp;
                tail = temp;
            } else {
                tail->next = temp;
                tail = temp;
            }
        }

        if (l1) {
            if (!head)
                head = l1;
            else
                tail->next = l1;
        }
        
        else if (l2) {
            if (!head)
                head = l2;
            else
                tail->next = l2;
        }
        return head;
    }
};
