class Solution {
public:
    static bool in_bounds(int i, int j, std::string_view str) {
        if (i < 0 || i >= str.size()) return false;
        if (j < 0 || j >= str.size()) return false;
        return true;
    }
    static std::string_view find_palindrome(int i, int j, std::string_view str) {
        if (j < i || !in_bounds(i, j, str)) return {};

        // odd init, non palindrome
        if (j == i + 1 && str[i] != str[j]) return {};
        
        while (i >= 0 && j < str.size() && str[i] == str[j]) {
            --i;
            ++j;
        }

        ++i;
        --j;
        
        auto size = j - i + 1;
        return str.substr(i, size);
    }
    string longestPalindrome(string s) {
        std::string_view best{};
        for (auto i{0}; i < s.size(); ++i) {
            // odd case
            auto p1 = find_palindrome(i, i, s);
            auto p2 = find_palindrome(i, i + 1, s);
            if (p1.size() > best.size()) {
                best = p1;
            }
            if (p2.size() > best.size()) {
                best = p2;
            }
        }
        return std::string(best);
    }
};
