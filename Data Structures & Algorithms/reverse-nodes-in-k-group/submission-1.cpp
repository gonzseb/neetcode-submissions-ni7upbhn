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
    int getListLength(ListNode* head) {
        int counter = 0;

        while (head) {
            ++counter; head = head->next;
        }

        return counter;
    }

    ListNode* reverseListIterative(ListNode* head) {
        ListNode* previous = nullptr;
        ListNode* current = head;

        while (current) {
            ListNode* next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }

        return previous;
    }

	ListNode* reverseKGroup(ListNode* head, int k) {
		int length = getListLength(head);
		int limit = length - (length % k);
		ListNode* new_head = nullptr;
		ListNode* last = head;
		ListNode* prev_tail = nullptr; // tracks tail of previously reversed group
		int i = k;
			
		while (last && (i <= limit)) {
			int counter = 1;
			ListNode* current = last;
			
			while (counter < k) {
				++counter; current = current->next;
			}
		
			ListNode* current_next = current->next;
			current->next = nullptr;
			reverseListIterative(last);
			last->next = current_next;

			if (i == k) {
				new_head = current;
			} else {
				prev_tail->next = current; // stitch previous tail → new group head
			}

			prev_tail = last; // last is the tail after reversal
			last = current_next;
			i += k;
		}
		
		return new_head;
	}
};
