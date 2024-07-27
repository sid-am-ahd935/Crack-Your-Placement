class Solution {
  public:
    int findPair(int n, int x, vector<int> &arr) {
        // Optimal solution, O(N) TC with O(N) SC
        // unordered_set<int> pair;
        
        // for(int a:arr) {
        //     if(pair.find(a-x) != pair.end() || pair.find(x+a) != pair.end()) {
        //         return 1;
        //     }
        //     pair.insert(a);
        // }
        
        // return -1;
        
        // As the expected TC is O(N logN) and SC is O(1), using sorting approach
        if(n == 1) {
            return -1;
        }
        sort(arr.begin(), arr.end());
        int p1 = 0, p2 = 1;
        while(p1 < n && p2 < n) {
            // Got an error in this if case, Todo revision
            // Error was I forgot to consider p1 == p2 will also help in edge cases
            if(p1 != p2 && arr[p2] - arr[p1] == x) {
                return 1;
            } else if(arr[p2] - arr[p1] < x) {
                p2++;
            } else {
                p1++;
            }
        }
        
        return -1;
    }
};
