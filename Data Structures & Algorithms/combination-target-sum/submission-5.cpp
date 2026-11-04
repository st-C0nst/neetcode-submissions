class Solution {
public:
    using Can = std::vector<int>;
    using Result = std::vector<Can>;
    
    struct State {
        Can candidate;
        int sum{};
    };
    void dfs(const int target_sum,State& state, Result& result, std::span<const int> search_space) {
        if (state.sum == target_sum) {
            result.push_back(state.candidate);
            return;
        }
        if (state.sum > target_sum || search_space.empty()) {
            return;
        }

        // include
        auto n = search_space.front();
        state.candidate.push_back(n);
        state.sum += n;
        dfs(target_sum, state, result, search_space);
        state.candidate.pop_back();
        state.sum -= n;

        // exclude
        dfs(target_sum, state, result, search_space.subspan(1));
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        Result res;
        State state{};
        dfs(target, state, res, nums);
        return res;
    }
};
