class Solution {
  void printDuplicates(string str) {
    int counts[26];
    for(char c:str) {
      counts[c-'a']++;
    }
    for(int i=0; i<26; i++) {
      if(counts[i] > 0) {
        cout << char('a'+ i) << ", count = " << counts[i] << endl;
      }
    }
    return;
  }
};
