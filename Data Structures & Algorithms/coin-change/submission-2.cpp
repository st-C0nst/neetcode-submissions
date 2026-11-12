class Solution {
public:
static constexpr auto inf = std::numeric_limits<int>::max();
    int coinChange(vector<int>& coins, int amount) {
        std::vector<int> dp(amount+1, inf);
        dp[0] = 0;
        
        for (int c{0}; c < coins.size(); ++c) {
            int coin = coins[c];
            for (int a = coin; a <= amount; ++a) {
                // only try to extend a valid bag
                if (dp[a-coin] != inf) {
                    dp[a] = std::min(dp[a], dp[a - coin] + 1);
                }
            }
        }

        return dp[amount] == inf ? -1 : dp[amount];
    }
};

// unbounded knapsack
// amount is like capacity
// every coin has some value
// base case is 0 coins added, max value for every capacity is 0
