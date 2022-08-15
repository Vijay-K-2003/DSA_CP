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
        // 8ms 14.8MB
        ListNode* mergedList = new ListNode(), *a = list1, *b = list2;
        ListNode* newhead = mergedList;
        while(a and b) {
            if(a->val > b->val) {
                mergedList->next = b;
                mergedList = mergedList->next;
                b = b->next;
            } else {
                mergedList->next = a;
                mergedList = mergedList->next;
                a = a->next;
            }
        }
        if(a) {
            while(a) {
                mergedList->next = a;
                a = a->next;
                mergedList = mergedList->next;
            }
        } else if (b) {
            while(b) {
                mergedList->next = b;
                b = b->next;
                mergedList = mergedList->next;
            }
        }
        return newhead->next;
    }
};
