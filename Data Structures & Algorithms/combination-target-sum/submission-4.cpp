#include <ranges>

class Solution {
public:
    using Stack = std::vector<int>;
    struct State {
        Stack combination{};
        int sum{};
    };
    using Res = std::vector<Stack>;
    static void dfs(State& state, Res& results, const int target, std::span<const int> nums) {
        if (state.sum == target) {
            results.push_back(state.combination);
            return;
        }

        const int old_sum = state.sum;
        for (const auto [index, n] : nums | std::views::enumerate) {
            const auto new_sum = state.sum + n;
            if (state.sum > target) {
                return;
            }
            state.sum = new_sum;
            state.combination.push_back(n);

            dfs(state, results, target, nums.subspan(index));

            state.sum = old_sum;
            state.combination.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        std::ranges::sort(nums);
        State state;
        state.combination.reserve(1 << nums.size());
        Res results{};
        dfs(state, results, target, nums);
        return results;
    }
};
