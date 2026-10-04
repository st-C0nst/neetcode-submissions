#include <cctype>

class Solution {
public:
    using TwoPointers = std::pair<int, int>;
    inline void shrink_left(TwoPointers& ptrs, string_view s) const {
        auto& [left, right] = ptrs;
        ++left;
        find_left(ptrs,s);
    }

    inline void shrink_right(TwoPointers& ptrs, string_view s) const {
        auto& [left, right] = ptrs;
        --right;
        find_right(ptrs,s);
    }

    inline void find_left(TwoPointers& ptrs, string_view s) const {
        auto& [left, right] = ptrs;
        while (left < right && !std::isalnum(s[left])) {
            ++left;
        }
    }
    inline void find_right(TwoPointers& ptrs, string_view s) const {
        auto& [left, right] = ptrs;
        while (right > left && !std::isalnum(s[right])) {
            --right;
        }
    }
    
    
    [[nodiscard]]
    inline bool same_chars(TwoPointers ptrs, string_view s) {
        const auto& [left, right] = ptrs;
        return std::tolower(s[left]) == std::tolower(s[right]);
    }
    
    bool isPalindrome(string s) {
        TwoPointers ptrs{0, s.size() - 1};
        find_left(ptrs, s);
        find_right(ptrs, s);
        
        while (ptrs.first < ptrs.second) {
            if (!same_chars(ptrs, s)) {
                return false;
            }
            shrink_left(ptrs, s);
            shrink_right(ptrs, s);
        }
        return true;
    }
};
