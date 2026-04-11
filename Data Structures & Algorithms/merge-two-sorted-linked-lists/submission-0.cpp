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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
                if (!list1) return list2;
        if (!list2) return list1;

        ListNode* mergedList = nullptr;

        if (list1->val < list2->val) {
            mergedList = list1;
            list1 = list1->next;
        } else {
            mergedList = list2;
            list2 = list2->next;
        }

        ListNode* mergedListLastNode = mergedList;

        while (list1 && list2) {
            if (list1->val < list2->val) {
                mergedListLastNode->next = list1;
                list1 = list1->next;
            } else {
                mergedListLastNode->next = list2;
                list2 = list2->next;
            }
            mergedListLastNode = mergedListLastNode->next;
        }

        if (!list1) mergedListLastNode->next = list2;
        if (!list2) mergedListLastNode->next = list1;

        return mergedList;
    }
};
