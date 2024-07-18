class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int tot_profit = 0;
        for(int i=1; i<prices.size(); i++) {
            if(prices[i] > prices[i-1]) {
                tot_profit += prices[i] - prices[i-1];
            }
        }
        return tot_profit;
    }
};
