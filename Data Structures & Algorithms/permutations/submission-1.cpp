#include <ranges>
constexpr auto max_len = 6;
constexpr auto factorials = [] {
    std::array<std::uint16_t, max_len> table{};
    table[0] = 1;
    for (int i = 1; i < max_len; ++i) {
        table[i] = i * table[i - 1];
    }
    return table;
}();

class Solution {
public:
    using Bool = std::uint8_t;
    using VisitSet = std::vector<Bool>;
    using Index = std::size_t;
    using Candidate = std::vector<int>;
    
    struct CandidateState {
        Candidate candidate;
        VisitSet visited;

        explicit CandidateState(const std::size_t capacity) : capacity_{capacity}, visited(capacity) {
            candidate.reserve(capacity);
        }
        
        [[nodiscard]]
        bool add(Index index, int num) {
            if (contains(index)) return false;
            candidate.push_back(num);
            visited[index] = 1;
            return true;
        }
        void remove(Index index) {
            candidate.pop_back();
            visited[index] = 0;
        }
        
        bool contains(Index index) const {
            return visited[index] != 0;
        }
        
        [[nodiscard]]
        bool is_valid() const {
            return candidate.size() == capacity_;
        }
        std::optional<std::span<const int>> get_candidate() {
            if (!is_valid()) return {};
            return candidate;
        }

        private:
            const std::size_t capacity_;
    };
    using Results = std::vector<Candidate>;
    
    static void dfs(CandidateState& state, Results& results, std::span<const int> nums) {
        if (auto candidate = state.get_candidate(); candidate) {
            results.push_back(std::ranges::to<vector<int>>(*candidate));
            return;
        }

        for (const auto [index, n] : nums | std::views::enumerate) {
            if (!state.add(index, n)) {
                continue;
            }
            dfs(state, results, nums);
            state.remove(index);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.empty()) return {};
        CandidateState state(nums.size());
        Results results;
        results.reserve(factorials[nums.size() - 1]);
        
        dfs(state, results, nums);
        return results;
    }
};
