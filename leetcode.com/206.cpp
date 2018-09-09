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
    ListNode* reverseList(ListNode* head) {
        ListNode* root = NULL, *t;

        while (head) {
            t = head->next;
            head->next = root;
            root = head;
            head = t;
        }

        return root;
    }
};
