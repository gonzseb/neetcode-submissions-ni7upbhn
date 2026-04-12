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
    ListNode* removeNthFromEndReference(ListNode* head, int& n) {
        if (!head) return nullptr;

        head->next = removeNthFromEndReference(head->next, n);

        --n;

        if (n == 0) {
            ListNode* next = head->next;
            delete head;
            return next;
        }

        return head;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        return removeNthFromEndReference(head, n);
    }
};
