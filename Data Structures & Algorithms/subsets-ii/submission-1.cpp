class Solution {
public:
using Can = std::vector<int>;
struct State {
    Can candidate;
    int sum{0};
};
using Result = std::vector<Can>;
    static void dfs(State& state, Result& res, std::span<const int> search_space) {
        if (search_space.empty()) {
            res.push_back(state.candidate);
            return;
        }

        const auto n = search_space.front();
        state.candidate.push_back(n);
        state.sum += n;
        dfs(state, res, search_space.subspan(1));
        state.sum -= n;
        state.candidate.pop_back();

        // exclude
        int i = 0;
        while (i < search_space.size() && search_space[i] == n) {
            ++i;
        }
        dfs(state, res, search_space.subspan(i));
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        std::ranges::sort(nums);
        State state{};
        Result res{};
        dfs(state, res, nums);
        return res;
    }
};
