class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> close = {
            {'{', '}'}, {'(', ')'}, {'[', ']'}
        };
        stack<char> bracs;
        for(char c:s) {
            if(close.find(c) != close.end()) {
                bracs.push(c);
            } else {
                if(bracs.empty()) return false;
                char open = bracs.top();
                bracs.pop();
                if(close[open] != c) {
                    return false;
                }
            }
        }
        return bracs.empty();
    }
};
