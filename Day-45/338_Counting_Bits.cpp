class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> arr(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            arr[i] = __builtin_popcount(i); // Efficient way to count set bits in an integer
        }
        return arr;
    }
};
