class Solution {
public:
    int rob(vector<int>& nums) {
        auto amount2 = 0;
        auto amount1 = 0;
        for (int i = nums.size() - 1; i >= 0; --i) {
            auto curr = std::max(nums[i] + amount1, amount2);
            amount1 = amount2;
            amount2 = curr;
        }
        return std::max(amount1, amount2);
    }
};

// subproblem: max money for the subarray from i to end
// recurrence: we can either rob the current house then skip our neighbor or we dont rob curr house and include neighbor
// robbed_amount[i] = std::max(house[i] + robbed_amount[i+2], robbed_amount[i+1]);
// base case: best answer for last house
// out of bounds is 0 money
// only need to store the prev 2