#include <vector>
class Solution {
public:
    using Candidate = std::vector<int>;
    using Results = std::vector<Candidate>;
    
    static void dfs(Candidate& candidate, Results& results, std::span<const int> search_space) {
        if (search_space.empty()) {
            results.push_back(candidate);
            return;
        }
        

        const int n = search_space.front();
        candidate.push_back(n);
        dfs(candidate, results, search_space.subspan(1));
        candidate.pop_back();

        // dont include value, skip all instances of the value
        int i = 1;
        while (i < search_space.size() && search_space[i] == n) {
            ++i;
        }
        dfs(candidate, results, search_space.subspan(i));
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        std::ranges::sort(nums);
        Candidate candidate;
        candidate.reserve(nums.size());
        Results results;
        results.reserve(1 << nums.size());
        dfs(candidate, results, nums);
        return results;
    }
};
