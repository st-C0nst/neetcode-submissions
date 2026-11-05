#include <ranges>
#include <print>
class Solution {
public:
    using Can = std::vector<int>;
    struct State {
        Can candidate;
        int sum{0};
    };
    using Result = std::vector<Can>;
    void dfs(const int target, State& state, Result& result, std::span<const int> search_space) {
        if (state.sum == target) {
            result.push_back(state.candidate);
            return;
        }
        if (state.sum > target || search_space.empty())  {
            return;
        }

        for (const auto [idx, n] : search_space | std::views::enumerate) {
            // include
            state.candidate.push_back(n);
            state.sum += n;
            dfs(target, state, result, search_space.subspan(idx));
            state.candidate.pop_back();
            state.sum -= n;
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        Result res;
        State state{};
        dfs(target, state, res, nums);
        return res;
    }
};
