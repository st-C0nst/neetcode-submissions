class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int min_price = prices.front();

        for (int day = 1; day < prices.size(); ++day) {
            if (prices[day] < min_price) {
                min_price = prices[day];
            }
            else {
                auto curr_profit = prices[day] - min_price;
                max_profit = max(curr_profit, max_profit);
            }
        }
        return max_profit;
    }
};
