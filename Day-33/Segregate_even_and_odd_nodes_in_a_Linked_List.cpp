class Solution {
  public:
    Node* divide(Node* head) {
        // code here
        Node *root = new Node(-1);
        root -> next = head;
        Node *prev = root, *curr = head, *end = head, *new_end;
        
        while(end -> next != NULL) {
            end = end -> next;
        }
        
        new_end = end;
        
        while(curr != end) {
            if((curr -> data)%2) {
                prev -> next = curr -> next;
                curr -> next = NULL;
                new_end -> next = curr;
                new_end = curr;
                
                // prev = prev -> next;
                curr = prev -> next;
            } else {
                prev = curr;
                curr = curr -> next;
            }
        }
        
        
        // When end is also an odd number
        if((end -> data)%2 != 0 && new_end != end) {
            // As curr == end, prev -> next = end
            prev -> next = end -> next;
            end -> next = NULL;
            new_end -> next = end;
            new_end = end;
            
            end = prev;
        }
        
        return root -> next;
    }
};
