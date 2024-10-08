class Solution {
public:
    vector<int> mostCompetitive(vector<int>& A, int k) {
        vector<int> stack(k);
        int j = 0, n = A.size();
        for (int i = 0; i < n; ++i) {
            while (j && stack[j - 1] > A[i] && j - 1 + n - i >= k)
                j--;
            if (j < k)
                stack[j++] = A[i];
        }
        return stack;
    }
};
