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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = nullptr;
        ListNode *tail = nullptr;
        int carry = 0;

        while (l1 && l2) {
            int sum = l1->val + l2->val + carry;
            carry = (sum >= 10) ? 1 : 0;

            auto n = new ListNode(sum % 10);

            if (!head)
                head = tail = n;
            else {
                tail->next = n;
                tail = n;
            }
            l1 = l1->next;
            l2 = l2->next;
        }

        if (l1) {
            while (l1) {
                int sum = l1->val + carry;
                carry = (sum >= 10) ? 1 : 0;

                auto n = new ListNode(sum % 10);
                if (!head)
                    head = tail = n;
                else {
                    tail->next = n;
                    tail = n;
                }
                l1 = l1->next;
            }
        } else if (l2) {
                while (l2) {
                    int sum = l2->val + carry;
                    carry = (sum >= 10) ? 1 : 0;
                    auto n = new ListNode(sum % 10);

                    if (!head)
                        head = tail = n;
                    else {
                        tail->next = n;
                        tail = n;
                    }
                    l2 = l2->next;
                }
            }

        // After all addition is done
        if (carry) {
            auto n = new ListNode(carry);
            tail->next = n;
            tail = n;
        }

        return head;
    }
};
