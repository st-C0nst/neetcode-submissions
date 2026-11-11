#include <ranges>
class Solution {
public:
    static int house_robber(std::span<const int> houses) {
        auto a1{0};
        auto a2{0};

        for (const auto money : houses | std::views::reverse) {
            auto curr = std::max(money + a1, a2);

            a1 = a2;
            a2 = curr;
        }
        return std::max(a1, a2);
    }
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums.back();
        std::span houses(nums);
        return std::max(house_robber(houses.subspan(1)), house_robber(houses.subspan(0, nums.size() - 1)));
    }
};

// harder because now it loops around
// two cases: if we rob the first house we cannot rob the last, if we rob the last house we cannot rob the first
// run house robber 1 on those 2 cases and return best asnwer
