class Solution {
public:
    using CharCounter = std::array<std::int16_t, 26>;
    static std::size_t index(unsigned char c) {
        return c - 'a';
    }
    static std::pair<CharCounter,std::size_t> count_chars(string_view s) {
        CharCounter counter{};
        std::size_t distinct_counts = 0;
        for (const auto c : s) {
            if (counter[index(c)]++ == 0) {
                ++distinct_counts;
            }
        }
        return {counter, distinct_counts};
    }
    bool checkInclusion(string s1, string s2) {
        if (s2.size() < s1.size()) return false;
        string_view str = s2;
        std::size_t window_len = s1.size();
        auto [counts, non_zero_counts] = count_chars(s1);
        int l = 0;
        
        for (int r = 0; r < s2.size(); ++r) {
            std::int16_t prev_count = counts[index(str[r])];
            std::int16_t new_count = --counts[index(str[r])];
            if (new_count == 0) {
                --non_zero_counts;
            }
            else if (prev_count == 0) {
                ++non_zero_counts;
            }
            

            while (l <= r && r - l + 1 > window_len) {
                std::int16_t prev_count = counts[index(str[l])];
                std::int16_t new_count = ++counts[index(str[l])];
                if (prev_count == 0) {
                    ++non_zero_counts;
                }
                if (new_count == 0) {
                    --non_zero_counts;
                }
                
                ++l;
            }
            
            if (non_zero_counts == 0) {
                return true;
            }
        }
        return false;
    }
};
