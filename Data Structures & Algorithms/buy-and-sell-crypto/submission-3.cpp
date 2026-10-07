class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int min_price = prices.front();

        for (auto price : prices) {
            auto curr_profit = price - min_price;
            max_profit = max(curr_profit, max_profit);
            min_price = min(min_price, price);
        }
        return max_profit;
    }
};
