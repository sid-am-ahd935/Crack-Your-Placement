class Solution {
  public:
    Node* reverselist(Node* head) {
        // Initialize prev and current pointers
        Node *prev = NULL, *curr = head, *next;
     
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    void printlist(Node* head) {
        while (head != NULL) {
            cout << head->data << " ";
            if (head->next)
                cout << "-> ";
            head = head->next;
        }
        cout << endl;
    }
    void reorderList(Node* head) {
        Node *slow = head, *fast = slow->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        Node* head1 = head;
        Node* head2 = slow->next;
        slow->next = NULL;
        
        // printlist(head1);
        // printlist(head2);
        head2 = reverselist(head2);
        // printlist(head2);
        
        head = new Node(0); 
        Node* curr = head;
        while (head1 || head2) {
            // First add the element from list
            if (head1) {
                curr->next = head1;
                curr = curr->next;
                head1 = head1->next;
            }
            // Then add the element from the second list
            if (head2) {
                curr->next = head2;
                curr = curr->next;
                head2 = head2->next;
            }
        }
        // Assign the head of the new list to head pointer
        head = head -> next;
    }
};
