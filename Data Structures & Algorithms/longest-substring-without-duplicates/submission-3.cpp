const unsigned char ascii_start = ' ';
const unsigned char ascii_end = '~';
consteval std::size_t get_ascii_range() {
    return ascii_end - ascii_start + 1;
}
using CharCounter = std::array<std::uint8_t, get_ascii_range()>;

class Solution {
public:
    std::size_t index(const unsigned char c) const  {
        return c - ascii_start;
    }

    void add_char(const unsigned char c, CharCounter& counter) const  {
        ++counter[index(c)];
    }
    void remove_char(const unsigned char c, CharCounter& counter) const {
        --counter[index(c)];
    }
    
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        CharCounter char_counts{};
        int max_len = 1;
        int l = 0;
        
        for (int r = l; r < s.size(); ++r) {
            add_char(s[r], char_counts);
            
            while (l <= r && char_counts[index(s[r])] > 1) {
                remove_char(s[l], char_counts);
                ++l;
            }
            
            max_len = max(r - l + 1, max_len);
        }
        return max_len;
    }
};
