class Solution {
public:
    using CharCounter = std::array<std::int16_t, 26>;
    static std::size_t index(unsigned char c) {
        return c - 'a';
    }

    static int add_char(unsigned char c, CharCounter& counts) {
        auto old_count = counts[index(c)];
        auto new_count = --counts[index(c)];
        if (old_count == 0) {
            return 1;
        }
        if (new_count == 0) {
            return -1;
        }
        return 0;
    }
    static int remove_char(unsigned char c, CharCounter& counts) {
        auto old_count = counts[index(c)];
        auto new_count = ++counts[index(c)];
        if (old_count == 0) {
            return 1;
        }
        if (new_count == 0) {
            return -1;
        }
        return 0;
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
        auto window_len = s1.size();
        auto [counts, non_zero_counts] = count_chars(s1);
        int l = 0;
        
        for (int r = 0; r < s2.size(); ++r) {
            non_zero_counts += add_char(str[r], counts);

            if (l <= r && r - l + 1 > window_len) {
                non_zero_counts += remove_char(str[l], counts);
                ++l;
            }
            
            if (non_zero_counts == 0) {
                return true;
            }
        }
        return false;
    }
};
