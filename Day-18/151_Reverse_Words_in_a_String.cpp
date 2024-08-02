class Solution {
public:
    string reverseWords(string s) {
        stack<string> rev;
        string res = "";
        string temp = "";

        for(char c:s) {
            if(c == ' ') {
                if(!temp.empty()) {
                    rev.push(temp);
                    temp = "";
                }
            } else {
                temp.push_back(c);
            }
        }
        if(!temp.empty()) {
            rev.push(temp);
        }
        res.append(rev.top());
        rev.pop();

        while(!rev.empty()) {
            res.push_back(' ');
            res.append(rev.top());
            rev.pop();
        }

        return res;
    }
};
