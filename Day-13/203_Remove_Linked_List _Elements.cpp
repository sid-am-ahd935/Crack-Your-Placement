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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* root = new ListNode(-1);
        ListNode *prev = root, *curr;
        root -> next = head;
        curr = root -> next;

        while(curr != NULL) {
            ListNode* next = curr -> next;
            if(curr -> val == val) {
                prev -> next = curr -> next;
                curr -> next = NULL;
                delete curr;
            } else {
                prev = curr;
            }
            curr = next;
        }

        return root -> next;
    }
};
