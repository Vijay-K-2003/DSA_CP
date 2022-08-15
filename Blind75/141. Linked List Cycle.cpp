/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        // 7ms code Extra temp variable used 8.1MB
        // ListNode* temp = new ListNode(0);
        // bool flag = false;
        // ListNode* cpy = head;
        // while(cpy != NULL) {
        //     if(cpy->next == temp) {
        //         flag = true;
        //         break;
        //     }
        //     ListNode* c = cpy;
        //     cpy = cpy->next;
        //     c->next = temp;
        // }
        // return flag; 
        
        // 10 ms no extra space used 7.9 MB
        ListNode* slow = head, * fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return true;
            }
        }
        return false;
    }
};
