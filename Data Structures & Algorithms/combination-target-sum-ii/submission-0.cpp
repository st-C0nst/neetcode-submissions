#include <ranges>

class Solution {
public:
    using Candidates = std::span<const int>;
    using Combination = std::vector<int>;
    struct CombinationState {
        Combination combination{};
        int sum_{};

        CombinationState(std::size_t n) {
            combination.reserve(n);
        }

        int sum() const {
            return sum_;
        }
        
        void add(int n) {
            combination.push_back(n);
            sum_ += n;
        }

        void remove() {
            // we know we wont remove on empty, skip
            // if (combination.empty())
            sum_ -= combination.back();
            combination.pop_back();
        }
    };
    
    static void dfs(CombinationState& state, std::vector<Combination>& results, Candidates candidates, const int target) {
        if (state.sum() == target) {
            results.push_back(state.combination);
            return;
        }

        for (int i = 0; i < candidates.size(); ++i) {
            if (i != 0 && candidates[i] == candidates[i - 1]) {
                continue;
            }
            const int n = candidates[i];
            const int new_sum = state.sum() + n;
            if (new_sum > target) {
                continue;
            }

            state.add(n);
            dfs(state, results, candidates.subspan(i + 1), target);
            state.remove();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::ranges::sort(candidates);
        
        CombinationState state(candidates.size());
        std::vector<Combination> results;
        results.reserve(1 << candidates.size());
        
        dfs(state, results, candidates, target);
        return results;
    }
};
