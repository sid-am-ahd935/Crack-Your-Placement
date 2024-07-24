class Solution {
public:
    bool validPalindrome(string s) {
        // Two Pointer Approach
        bool left = false, right = false;
        int p1 = 0, p2 = s.size()-1, P1, P2;

        while(p1 < p2 && (left = right = s[p1] == s[p2])) {
            p1++;
            p2--;
        }

        // Check if delete at left or right working
        if(!left) {
            P1 = p1+1, P2 = p2;
            while(P1 <= P2 && (left = s[P1] == s[P2])) {
                P1++;
                P2--;
            }
            P1 = p1, P2 = p2-1;
            while(P1 <= P2 && (right = s[P1] == s[P2])) {
                P1++;
                P2--;
            }
        }
        
        return left || right;
    }
};
