class Solution {
public:
    static std::optional<int> can_eat_pile(const int num_bananas, const int eating_rate, const int hours) {
        auto time_to_eat = num_bananas / eating_rate;
        if (num_bananas % eating_rate != 0) {
            time_to_eat += 1;
        }
        
        if (time_to_eat > hours) return {};
        return time_to_eat;
    }
    static bool can_eat_bananas(std::span<const int> bananas, const int eating_rate, const int hours) {
        int remaining_hours = hours;
        
        for (const auto pile : bananas) {
            if (remaining_hours <= 0) {
                return false;
            }
            
            if (auto dt = can_eat_pile(pile, eating_rate, hours); dt) {
                remaining_hours -= dt.value();
            }
            else {
                return false;
            }
        }
        return remaining_hours >= 0;
    }

    int find_min_eating_rate(std::span<const int> piles, const int hours) {
        int l = 1;
        int r = std::ranges::max(piles);
        
        while (l < r) {
            const int rate = l + (r - l) / 2;
            if (can_eat_bananas(piles, rate, hours)) {
                r = rate;
            }
            else {
                l = rate + 1;
            }
        }
        return l;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        return find_min_eating_rate(piles, h);
    }
};
