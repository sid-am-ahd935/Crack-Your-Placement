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
    bool isPalindrome(ListNode* head) {
        string str = "", rev = "";
        ListNode* curr = head;
        while(curr != NULL) {
            str.push_back('0' + (curr -> val));
            curr = curr -> next;
        }

        rev = str;
        reverse(rev.begin(), rev.end());

        return str == rev;
    }
};
