#include <ranges>

class Solution {
public:
    static int time_to_eat(int rate, int pile_size) {
        return ((pile_size + rate - 1) / rate);
    }

    static bool can_eat(int rate, int hours,std::span<const int> piles) {
        for (const auto pile : piles) {
            if (hours <=0) {
                return false;
            }
            hours -= time_to_eat(rate, pile);
        }

        return hours >= 0;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        auto max_pile = *std::ranges::max_element(piles);
        auto rates = std::views::iota(1, max_pile + 1);
        auto best_rate = std::ranges::partition_point(rates, [&](const auto& r) {
            return !can_eat(r, h, piles);
        });
        return *best_rate;
    }
};
