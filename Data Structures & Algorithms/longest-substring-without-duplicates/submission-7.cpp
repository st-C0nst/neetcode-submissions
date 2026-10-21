#include <array>

constexpr std::size_t first_num = ' ';
constexpr std::size_t num_range = '~' - first_num + 1;
class Solution {
public:
    std::array<std::uint8_t, num_range> counts{};
    int lengthOfLongestSubstring(string s) {
        int max_len = 0;
        int duplicate_count = 0;
        int l = 0;
        for (int r = 0; r < s.size(); ++r) {
            if (counts[s[r] - first_num]++ == 1) {
                ++duplicate_count;
            }
            
            while (l < r && duplicate_count > 0) {
                if (counts[s[l] - first_num]-- == 2) {
                    --duplicate_count;
                }
                ++l;
            }

            auto window_len = r - l + 1;
            max_len = max(window_len, max_len);
        }
        return max_len; 
    }
};
