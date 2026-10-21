class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0;
        int max_profit = 0;

        for (int r = 1; r < prices.size(); ++r) {
            if (prices[r] < prices[l]) {
                l = r;
            }
            else {
                auto curr_profit = prices[r] - prices[l];
                max_profit = max(curr_profit, max_profit);
            }
        }
        return max_profit;
    }
};

