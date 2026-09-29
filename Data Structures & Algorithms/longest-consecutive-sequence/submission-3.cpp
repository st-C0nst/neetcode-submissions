#include <unordered_set>
#include <optional>

class Solution {
public:
    struct SeqStart {
        int value;
        
        operator int() const {
            return value;
        }
    };
    
    std::optional<SeqStart> is_sequence_start(int num, const unordered_set<int>& nums) const {
        if (!nums.contains(num - 1)) {
            return SeqStart{num};
        }
        return {};
    }
    // Assume that num passed in is seq start
    int get_sequence_length(SeqStart start, const unordered_set<int>& nums) const {
        int len = 1;
        for (int i = start + 1; nums.contains(i); ++i) {
            ++len;
        }
        return len;
    }
    
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        unordered_set<int> nums_set(nums.begin(), nums.end());
        int longest_len = 1;
        for (const auto& num : nums) {
            if (auto start = is_sequence_start(num, nums_set); start.has_value()) {
                auto curr_len = get_sequence_length(start.value(), nums_set);
                longest_len = max(curr_len, longest_len);
            }
        }
        return longest_len;
    }
};
