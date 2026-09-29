#include <unordered_map>
#include <tuple>
#include <ranges>

class Solution {
public:
    using CharCount = std::array<std::uint16_t, 26>;
    struct CharCountHash {
        std::size_t operator()(const CharCount& counts) const noexcept {
            std::size_t hash{};
            for (const auto& count : counts) {
                hash = hash * 31 + count;
            }
            return hash;
        }
    };
    CharCount make_anagram_id(std::string_view str) const {
        CharCount char_counts{};
        for (const auto& c : str) {
            ++char_counts[c - 'a'];
        }
        return char_counts;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<CharCount, vector<string>, CharCountHash> groups_by_anagram;
        for (auto& str : strs) {
            groups_by_anagram[make_anagram_id(str)].emplace_back(std::move(str));
        }

        vector<vector<string>> grouped_strings{};
        grouped_strings.reserve(groups_by_anagram.size());
        for (auto& group : groups_by_anagram | std::views::values) {
            grouped_strings.push_back(std::move(group));
        }
        return grouped_strings;
    }
};
