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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // Logic: Set aside the intersecting nodes, length of A  - intersected + length of B - intersected will be same for both cases

        ListNode *currA = headA, *currB = headB;
        bool swapA = true, swapB = true;

        while(currA != NULL && currB != NULL) {
            if(currA == currB) {
                break;
            }
            currA = currA -> next;
            currB = currB -> next;

            if(currA == NULL && swapA == true) {
                currA = headB;
                swapA = false;
            }
            if(currB == NULL && swapB == true) {
                currB = headA;
                swapB = false;
            }
        }

        return currA;
    }
};
