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
    ListNode* deleteDuplicates(ListNode* head) {
        // Using direct 2 pointer approach instead of any conversion
        ListNode *unique, *duplicate;
        unique = duplicate = head;

        while(duplicate != NULL) {
            if(duplicate -> val != unique -> val) {
                unique = duplicate;
            } else {
                duplicate = duplicate -> next;
                unique -> next = duplicate;
            }
        }
        
        return head;
    }
};
