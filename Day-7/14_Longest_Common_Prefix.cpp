class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";

        for(int i=0; i<strs[0].size(); i++) {
            char c = strs[0][i];
            bool flag = false;
            for(string& str:strs) {
                flag = (str.size() >= i && str[i] == c);
                if(!flag) break;
            }
            if(!flag) break;
            res.push_back(strs[0][i]);
        }
        return res;
    }
};
