class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        // The window sliding approach
        // The elements outside the window will be the elements that will be picked out
        int sum = accumulate(cardPoints.begin(), cardPoints.end(), 0);
        int ans = 0;

        int window = 0;
        int nk = cardPoints.size()-k;   // Size of elements that will not be in k, i.e., inside the window
        // Initially fill the window
        for(int i=0; i<nk; i++) {
            window += cardPoints[i];
        }
        ans = max(ans, sum-window);
        // Sliding window to remove cards from selection
        for(int i=0; i<cardPoints.size()-nk; i++) {     // Could have written just k, but this window sliding constraint is more intuitive
            window -= cardPoints[i];
            window += cardPoints[i+nk];
            ans = max(ans, sum-window);
        }

        return ans;
    }
};
