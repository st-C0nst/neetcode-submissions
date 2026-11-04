class Solution {
public:
    using Candidate = std::vector<int>;
    using Results = std::vector<std::vector<int>>;
    void dfs(Candidate& candidate, Results& results, std::span<const int> search_space) {
        if (search_space.empty()) {
            results.push_back(candidate);
            return;
        }

        // include
        candidate.push_back(search_space.front());
        dfs(candidate, results, search_space.subspan(1));
        candidate.pop_back();

        // dont include
        dfs(candidate, results, search_space.subspan(1));
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        Candidate can;
        can.reserve(nums.size());
        Results results;
        dfs(can, results, nums);
        return results;
    }
};
