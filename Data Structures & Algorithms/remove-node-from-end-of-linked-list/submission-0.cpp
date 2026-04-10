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
    int getListSize(ListNode* head) {
        int size = 0;
        
        while (head) {
            ++size;
            head = head->next;
        }

        return size;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) return nullptr;

        int list_size = getListSize(head);

        if (n == list_size) {
            head = head->next;
            return head;
        }

        if ((n < 1) || (n > list_size )) return head;

        int previous_node_index = list_size - n;
        int counter = 1;
        ListNode* aux = head;

        while (counter < previous_node_index) {
            aux = aux->next; ++counter;
        }

        aux->next = aux->next->next;

        return head;
    }
};
