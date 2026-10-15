#include <ranges>
using LetterMap = std::array<string, 8>;
constexpr LetterMap lookup = {{
    "abc",
    "def",
    "ghi",
    "jkl",
    "mno",
    "pqrs",
    "tuv",
    "wxyz"
}};
class Solution {
public:
    static string_view get_letters(std::uint8_t num) {
        return lookup[num - 2];
    }
    static std::uint8_t to_num(unsigned char c) {
        return c - '0';
    }
    struct State {
        string candidate;
    };
    using Results = std::vector<string>;
    void dfs(State& state, Results& results, string_view digits) {
        if (digits.empty()) {
            results.push_back(state.candidate);
            return;
        }
        std::uint8_t num = to_num(digits[0]);
        auto letters = get_letters(num);
        for (int i = 0; i < letters.size(); ++i) {
            const auto letter = letters[i];
            
            state.candidate.push_back(letter);
            dfs(state, results, digits.substr(1));
            state.candidate.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        Results results{};
        State state{};
        state.candidate.reserve(digits.size());
        dfs(state, results, digits);
        return results;
    }
};
