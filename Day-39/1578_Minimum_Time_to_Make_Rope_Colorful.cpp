class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int res = 0;
        int comparedTime = neededTime[0];

        for (int i = 1; i < colors.length(); i++) {
            if (colors[i] == colors[i - 1]) {
                res += min(neededTime[i], comparedTime);
                comparedTime = max(neededTime[i], comparedTime);
            } else {
                comparedTime = neededTime[i];
            }
        }

        return res;        
    }
};
