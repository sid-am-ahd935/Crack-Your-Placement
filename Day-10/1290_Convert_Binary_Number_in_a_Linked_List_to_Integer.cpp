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
    int getDecimalValue(ListNode* head) {
        // Using a great stl function to convert binary string to decimal
        // strtoull - str to unsigned long long --------- didn't work, 
        // stoi comes to the rescue

        string number = "";
        while(head != NULL) {
            number.push_back('0' + head->val);
            head = head -> next;
        }

        int num = stoi(number, 0, 2);
        return num;
    }
};
