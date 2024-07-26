class Solution {
public:
    string addBinary(string a, string b) {
        // Had some issues due to me forgetting there would be different sizes of string as well, so added the last two for loops just for that.
        // Code is self explanatory just dry run with an example such as a = 1101101001, b = 111111
        string rev_res = "";
        char carry = '0';

        for(int i=a.size()-1, j=b.size()-1; i >= 0 && j >= 0; i--, j--) {
            if(a[i] == b[j]) {
                rev_res.push_back(carry);
                carry = a[i];
            } else {
                rev_res.push_back(carry == '1' ? '0' : '1');
                carry = carry == '1' ? '1' : '0';
            }
        }
        for(int i=a.size()-b.size()-1; i>=0; i--) {
            rev_res.push_back(carry == a[i] ? '0' : '1');
            carry = carry == '1' && a[i] == '1' ? '1' : '0';
        }
        for(int i=b.size()-a.size()-1; i>=0; i--) {
            rev_res.push_back(carry == b[i] ? '0' : '1');
            carry = carry == '1' && b[i] == '1' ? '1' : '0';
        }
        if(carry == '1') rev_res.push_back('1');
        

        cout << "Before reversing: " << rev_res << endl;

        reverse(rev_res.begin(), rev_res.end());
        cout << "After reversing: " << rev_res << endl;
        return rev_res;
    }
};
