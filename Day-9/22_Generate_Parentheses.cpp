class Solution {
private:
    void generate(int open, int close, int n, bool can_close, string curr, vector<string>& res) {
        if(open == n && close == n) {
            res.push_back(curr);
            return;
        }

        if(open < n) {
            curr.push_back('(');
            generate(open+1, close, n, true, curr, res);
            curr.pop_back();
        }

        if(can_close && close < n) {
            curr.push_back(')');
            generate(open, close+1, n, open > close+1, curr, res);
            curr.pop_back();
        }
        return;
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generate(0, 0, n, false, "", res);
        return res;
    }
};
