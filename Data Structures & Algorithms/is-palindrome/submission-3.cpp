#include <print>

class Solution {
public:
    int find_left_start(string_view s) const {
        int left = 0;
        while (left < s.size() && !std::isalnum(s[left])) {
            ++left;
        }
        return left;
    }
    
    int find_right_end(string_view s) const {
        int right = s.size() - 1;
        
        while (right >= 0 && !std::isalnum(s[right])) {
            --right;
        }
        return right;
    }
    
    bool is_palindrome(string_view s) {
        auto left = find_left_start(s);
        auto right = find_right_end(s);
        
        if (left >= right) return true;
        
        return std::tolower(s[left]) == std::tolower(s[right]) && is_palindrome(s.substr(left + 1, right - left - 1));
    }
    bool isPalindrome(string s) {
        return is_palindrome(s);
    }
};
