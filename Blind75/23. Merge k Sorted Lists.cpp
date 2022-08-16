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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if (n == 0) return NULL;
        while (n > 1) {
            for (int i = 0 ; i < n / 2 ; i++) {
                lists[i] = mergeTwoLists(lists[i], lists[n-i-1]);
            }
            n = (n+1)/2;
        }
        return lists.front();
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // 8ms 14.8MB
        if(list1 == NULL and list2 == NULL) return NULL;
        else if(list1 == NULL) return list2;
        else if(list2 == NULL) return list1;
        ListNode* mergedList = new ListNode(), *a = list1, *b = list2;
        ListNode* newhead = mergedList;
        while(a and b) {
            if(a->val > b->val) {
                mergedList->next = b;
                b = b->next;
            } else {
                mergedList->next = a;
                a = a->next;
            }
            mergedList = mergedList->next;

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
