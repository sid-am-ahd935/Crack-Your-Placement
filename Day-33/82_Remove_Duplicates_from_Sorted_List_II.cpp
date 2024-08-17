class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // Handle edge cases where the list is empty or has only one node
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;
        ListNode* curr = head;

        while (curr != NULL) {
            if (curr->next != NULL && curr->val == curr->next->val) {
                while (curr->next != NULL && curr->val == curr->next->val) {
                    curr = curr->next;
                }
                prev->next = curr->next;
            } else {
                prev = curr;
            }
            curr = curr->next;
        }

        return dummy->next;
    }
};
