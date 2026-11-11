#include <print>
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if (cost.size() == 1) {
            return cost.back();
        }
        if (cost.size() == 2) {
            return min(cost.back(), *(cost.end() - 2));
        }
        const auto n = cost.size();
        auto min_c1 = cost[n - 1];
        auto min_c2 = cost[n - 2];

            
        for (int step = n - 3; step >= 0; --step) {
            auto curr = std::min(min_c2, min_c1) + cost[step];
            min_c1 = min_c2;
            min_c2 = curr;
        }
        return std::min(min_c2, min_c1);
    }
};

// subproblem: given that I am on step i, what is the min cost to reach to top stair
// basecase: at nth step its cost[n], cost of n-1 is cost[n-1] + min_cost[n]
// choose step 1 or step 2, choose the min cost
// recurrence: min_cost[i] = min(min_cost[i+1], min_cost[i+2]) + cost[i];
// space saving: only store the 2 prev
// start at n - 2, jump to n -1 and n, 

// can choose diff steps at the end so pick min of min_cost[0], min_cost[1]
// 