#include <ranges>
class Solution {
public:
    using Candidate = std::vector<int>;
    using Results = std::vector<std::vector<int>>;
    void dfs(Candidate& candidate, Results& results, std::span<const int> search_space) {
        results.push_back(candidate);

        for (const auto [idx, n] : search_space | std::views::enumerate) {
            candidate.push_back(n);
            dfs(candidate, results, search_space.subspan(idx + 1));
            candidate.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        Candidate can;
        can.reserve(nums.size());
        Results results;
        dfs(can, results, nums);
        return results;
    }
};
