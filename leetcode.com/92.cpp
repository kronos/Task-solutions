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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* root = head, *prev = head, *last = NULL, *p, *z;
        for (int i = 1; i < m; i++) {
            prev = root;
            root = root->next;
        }

        p = root;
        for (int i = m; i < n; i++) {
            ListNode* t = p->next, *x = root;
            cout << (t==NULL) << endl;
            root = p->next;
            p->next = t->next;
            root->next = x;
        }

        if (m == 1) {
            head = root;
        } else if (m < n) {
            prev->next = root;
        }

        return head;
    }
};
