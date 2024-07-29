class Solution {
    private:
    Node* reverse(Node* head) {
        Node *prev = NULL, *curr = head;
        
        while(curr != NULL) {
            Node* next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
    void print(Node *head) {
        Node *curr = head;
        while(curr != NULL) {
            cout << (curr -> data) << ", ";
            curr = curr -> next;
        } cout << endl;
        return;
    }
    public:
    Node *compute(Node *head) {
        
        Node *curr = head;
        // print(curr);
        curr = reverse(curr);
        // print(curr);
        Node *prev = NULL, *rev = curr;
        
        while(curr != NULL) {
            if(prev == NULL) {
                prev = curr;
                curr = curr -> next;
            } else if(curr -> data  < prev -> data) {
                curr = curr -> next;
                if(curr == NULL) prev -> next = curr;
            } else {
                prev -> next = curr;
                prev = curr;
                curr = curr -> next;
            }
        }
        
        // print(rev);
        rev = reverse(rev);
        // print(rev);
        
        return rev;
    }
    
};
