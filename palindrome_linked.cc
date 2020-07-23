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
    bool isPalindrome(ListNode* head) {

        std::vector<int> vec;
        while (head) {
            vec.push_back(head->val);
            head = head->next;
        }

        int front = 0;
        int back = vec.size() - 1;
        while (front < back)
            if (vec.at(front++) != vec.at(back--))
                return false;
        return true;
    }
};
