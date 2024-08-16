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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *curr, *root = new ListNode(-1);
        root -> next = head;
        curr = head;

        int size = 0;
        while(curr) {
            curr = curr -> next;
            size++;
        }

        n = size - (n-1);
        curr = root;

        while(--n) {
            curr = curr -> next;
        }
        if(curr -> next) {
            curr -> next = curr -> next -> next;
        }

        return root -> next;
    }
};
