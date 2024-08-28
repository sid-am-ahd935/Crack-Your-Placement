class Solution {
public:
    int numTrees(int n) {
        std::vector<int> sol(n + 1, 0);
        sol[0] = sol[1] = 1;

        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                sol[i] += sol[i - j] * sol[j - 1];
            }
        }
        return sol[n];
    }
};
