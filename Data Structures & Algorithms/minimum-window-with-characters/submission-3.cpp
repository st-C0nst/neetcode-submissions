#include <array>
class Solution {
public:
    static constexpr char start = 'A';
    static constexpr char end = 'z';
    static constexpr std::size_t char_range = end - start + 1;
    std::array<int32_t, char_range> counts{};
    std::int32_t& get_count(unsigned char c) {
        return counts[c - start];
    }
    
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";
        
        // firstly init the counts
        int num_diff = 0;
        for (const auto c : t) {
            if (++get_count(c) > 0) {
                ++num_diff;
            }
        }
        int min_size = std::numeric_limits<int>::max();
        int start = -1;

        int l = 0;
        for (int r = 0; r < s.size(); ++r) {
            if (get_count(s[r])-- > 0) {
                --num_diff;
            }

            while (num_diff == 0) {
                auto curr_len = r - l + 1;
                if (curr_len < min_size) {
                    start = l;
                    min_size = curr_len;
                }

                if (++get_count(s[l]) > 0) {
                    ++num_diff;
                }
                ++l;
            }
        }
        if (start == -1) return "";
        return std::string(s.substr(start, min_size));
    }
};
