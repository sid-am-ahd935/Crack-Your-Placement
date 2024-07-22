class Solution {
public:
    int strStr(string haystack, string needle) {
        for(int i=0; i<haystack.size(); i++) {
            bool flag = false;
            for(int j=0; j<needle.size() && (flag = haystack[i+j] == needle[j]); j++) {}
            if(flag) return i;
        }

        return -1;
    }
};
