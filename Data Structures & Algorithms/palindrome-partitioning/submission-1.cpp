#include <ranges>
class Solution {
public:
    static bool is_palindrome(std::string_view str) {
        int l = 0, r = str.size() - 1;
        while (l < r) {
            if (str[l] != str[r]) {
                return false;
            }
            ++l;
            --r;
        }
        return true;
    }
    using Candidate = std::vector<std::string_view>;
    using Results = std::vector<Candidate>;
    static void dfs(Candidate& candidate, Results& results, string_view search_space) {
        if (search_space.empty()) {
            results.push_back(candidate);
            return;
        }

        for (int i = 1; i <= search_space.size(); ++i) {
            auto new_substr = search_space.substr(0, i);
            if (!is_palindrome(new_substr)) {
                continue;
            }

            candidate.push_back(new_substr);
            dfs(candidate, results, search_space.substr(i));
            candidate.pop_back();
        }
    }
    
    vector<vector<string>> partition(string s) {
        Candidate candidate{};
        candidate.reserve(s.size());
        Results results{};
        results.reserve(1 << s.size());

        dfs(candidate, results, s);
        return results | std::views::transform([](auto&& res) {
            return res | std::views::transform([](auto&& partition) {
                return string(partition);
            }) | std::ranges::to<std::vector<string>>();
        }) | std::ranges::to<vector<vector<string>>>();
    }
};
