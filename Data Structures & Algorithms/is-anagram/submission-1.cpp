#include <print>
#include <array>

class Solution {
public:
    struct CharCounter {
        public:
        using Container = std::array<int,26>;

        int& operator[](char c) {
            return counts[c - 'a'];
        }
        const int& operator[](char c) const {
            return counts[c - 'a'];
        }

        auto begin() noexcept {return counts.begin();}
        auto end() noexcept {return counts.end();}
        
        auto begin() const noexcept {return counts.begin();}
        auto end() const noexcept { return counts.end(); }
        
        static CharCounter count(string_view str) {
            CharCounter char_counts;
            for (const auto& c : str) {
                ++char_counts[c];
            }
            return char_counts;
        }
        
        bool all_zero() const noexcept {
            for (const auto& count : counts) {
                if (count != 0) return false;
            }
            return true;
        }
        
        private:
            Container counts{};
    };
    
    
    
    bool isAnagram(string s, string t) {
        auto s_counts = CharCounter::count(s);
        
        for (const auto& c : t) {
            // Early exit
            if (--s_counts[c] < 0) {
                return false;
            }
        }
        
        return s_counts.all_zero();
    }
};
