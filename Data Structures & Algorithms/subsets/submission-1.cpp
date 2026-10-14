#include <ranges>

class Solution {
public:
    using Stack = std::vector<int>;
    using Subsets = std::vector<std::vector<int>>;
    static void backtracking(Stack& subset, Subsets& subsets, std::span<const int> search_space) {
        // if valid pushback
        subsets.push_back(subset);
        
        for (const auto [index, n] : search_space | std::views::enumerate) {
            // prune
            // should be nothing to prune

            // add to state 
            subset.push_back(n);

            backtracking(subset, subsets, search_space.subspan(index + 1, search_space.size() - (index + 1)));

            // pop back
            subset.pop_back();
        }
        
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        Stack subset;
        subset.reserve(nums.size());
        Subsets subsets{};
        subsets.reserve(1 << nums.size());

        backtracking(subset, subsets, nums);
        return subsets;
    }
};
