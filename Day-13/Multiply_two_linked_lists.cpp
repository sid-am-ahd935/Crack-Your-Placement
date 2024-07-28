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
    void print(Node* head) {
        Node *curr = head;
        while(curr != NULL) {
            cout << (curr -> data) << ", ";
            curr = curr -> next;
        }
        cout << endl;
        return;
    }
  public:
    long long multiplyTwoLists(Node *first, Node *second) {
        long long mod = pow(10, 9) + 7, mul = 1;
        long long num1 = 0, num2 = 0;
        Node *curr;
        first = reverse(first);
        second = reverse(second);
        
        curr = first;
        mul = 1;
        while(curr != NULL) {
            num1 = curr -> data * mul + num1;
            mul *= 10;
            mul %= mod;
            num1 %= mod;
            curr = curr -> next;
        }
        curr = second;
        mul = 1;
        while(curr != NULL) {
            num2 = curr -> data * mul + num2;
            mul *= 10;
            mul %= mod;
            num2 %= mod;
            curr = curr -> next;
        }
        
        return (num1 * num2)%mod;
    }
};
