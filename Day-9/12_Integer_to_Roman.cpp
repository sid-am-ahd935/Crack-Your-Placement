class Solution {
private:
    string mulCh(int n, char c) {
        string res = "";
        while(n--) res.push_back(c);
        return res;
    }
public:
    string intToRoman(int num) {
        string res = "";
        int divisor = 1000;
        vector<vector<char>> roman = {
            {'I', 'V'},
            {'X', 'L'},
            {'C', 'D'},
            {'M', 'Z'}      // Z is not known here and will not be used as per constraints, added for code simplicity
        };

        while(num > 0) {
            int quo = num/divisor;
            if(quo == 9) {
                res.push_back(roman[log10(divisor)][0]);
                res.push_back(roman[log10(divisor)+1][0]);
            } else if(quo == 4) {
                res.push_back(roman[log10(divisor)][0]);
                res.push_back(roman[log10(divisor)][1]);
            } else {
                quo/5 ? res.push_back(roman[log10(divisor)][1]) : void();
                res.append(mulCh(quo%5, roman[log10(divisor)][0]));
            }
            if(divisor <= 0) divisor = 1;
            num %= divisor;
            divisor /= 10;
        }
        return res;
    }
};
