#include <string>
#include <ranges>
#include <cctype>

class Solution {
public:
    bool isPalindrome(string s) {
        auto chars = s | std::views::filter([](unsigned char c){
            return std::isalnum(c);
        }) | std::views::transform([](unsigned char c) {
            return static_cast<char>(std::tolower(c));
        });
        auto half = std::ranges::distance(chars) / 2;

        auto pairs = std::views::zip(
            chars, 
            chars | std::views::reverse
        ) | std::views::take(half);

        return std::ranges::all_of(pairs, [](auto pair) {
            const auto [first, second] = pair;
            return first == second;
        });
    }
};
