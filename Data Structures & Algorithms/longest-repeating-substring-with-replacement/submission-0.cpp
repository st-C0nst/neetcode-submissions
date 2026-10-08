class Solution {
public:
    using CharCounter = std::array<std::uint32_t, 26>;
    static std::size_t index(unsigned char c) {
        return c - 'A';
    }
    static bool is_valid(const int l, const int r, const int max_freq, const int k) {
        int len = (r - l) + 1;
        int max_valid_len = max_freq + k;
        return len <= max_valid_len;
    }
    
    int characterReplacement(string s, int k) {
        CharCounter char_counts{};

        int l = 0;
        int max_freq = 0;
        int max_len = 0;
        
        for (int r = 0; r < s.size(); ++r) {
            auto count = ++char_counts[index(s[r])];
            max_freq = max(max_freq, static_cast<int>(count));

            while (l <= r && !is_valid(l, r, max_freq, k)) {
                --char_counts[index(s[l])];
                ++l;
            }
            
            max_len = max(max_len, r - l + 1);
        }
        return max_len;
    }
};
