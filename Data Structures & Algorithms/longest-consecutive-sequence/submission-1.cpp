#include <unordered_set>
#include <algorithm>

class Solution {
public:
    [[nodiscard]]
    inline std::pair<int,int> find_sequence(const unordered_set<int>& sequence, int seed) const {
        const auto start = find_sequence_start(sequence,seed);
        const auto end = find_sequence_end(sequence, seed);
        
        return {start, end};
    }


    [[nodiscard]]
    inline int get_sequence_length(const unordered_set<int>& sequence, int seed) {
        if (auto it = seq_cache_.find(seed); it != seq_cache_.end()) {
            const auto [start, end] = it->second;
            return end - start + 1;
        }

        const auto [start, end] = find_sequence(sequence, seed);
        const auto len = end - start + 1;
        for (int i = start; i <= end; ++i) {
            seq_cache_[i] = {start, end};
        }
        return len;
    }
    
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        unordered_set<int> visited(nums.begin(), nums.end());
        
        int largest_seq_len = 1;
        
        for (const auto& n : nums) {
            largest_seq_len = std::max(get_sequence_length(visited, n), largest_seq_len);
        }
        return largest_seq_len;
    }
    private:
        [[nodiscard]]
        inline int find_sequence_start(const unordered_set<int>& visited, int init) const {
            int start = init - 1;
            for (; visited.contains(start); --start) {}
            return start + 1;
        }

        inline int find_sequence_end(const unordered_set<int>& visited, int init) const {
            int end = init + 1;
            for (; visited.contains(end); ++end) {}
            return end - 1;
        }
    
        std::unordered_map<int, std::pair<int,int>> seq_cache_;
};
