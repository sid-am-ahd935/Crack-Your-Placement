class Solution {
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        int count[3] = {0};
        Node *curr = head;
        while(curr != NULL) {
            count[curr -> data]++;
            curr = curr -> next;
        }
        
        head = new Node(-1);
        curr = head;
        for(int i=0; i<3; i++) {
            while(count[i]--) {
                curr -> next = new Node(i);
                curr = curr -> next;
            }
        }
        
        return head -> next;
    }
};
