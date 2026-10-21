#include <array>

class Solution {
public:
    std::array<uint32_t, 26> counts{};
    uint32_t& get_count(unsigned char c) {
        return counts[c - 'A'];
    }
    
    int characterReplacement(string s, int k) {
        int max_freq = 0;
        int max_len = 0;
        
        int l = 0;
        for (int r = 0; r < s.size(); ++r) {
            if (++get_count(s[r]) > max_freq) {
                max_freq = get_count(s[r]);
            }
            
            while (l < r && (r - l + 1) - max_freq > k) {
                --get_count(s[l]);
                ++l;
            }
            
            max_len = max(max_len, r - l + 1);
        }
        return max_len;
    }
};
