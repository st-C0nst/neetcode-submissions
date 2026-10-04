#include <ranges>

class Solution {
public:
    using TwoPointer = std::pair<int, int>;
    
    void shrink_left(TwoPointer& ptrs, const vector<int>& nums) const {
        auto& [left, right] = ptrs;
        ++left;
        while (left < right && nums[left] == nums[left - 1]) {
            ++left;
        }
    }
    void shrink_right(TwoPointer& ptrs, const vector<int>& nums) const {
        auto& [left, right] = ptrs;
        --right;
    }
    
    enum class SumCompare {Low, High, Equal};
    [[nodiscard]]
    inline SumCompare compare_target_sum(const TwoPointer ptrs, const int target, const vector<int>& nums) const {
        const auto [left, right] = ptrs;
        const int sum = nums[left] + nums[right];
        
        if (sum == target) {
            return SumCompare::Equal;
        }
        else if (sum > target) {
            return SumCompare::High;
        }
        else {
            return SumCompare::Low;
        }
    }
    
    vector<TwoPointer> two_sum_2(const TwoPointer bounds, int target, const vector<int>& nums) const {
        vector<TwoPointer> res;
        TwoPointer ptrs = bounds;

        while (ptrs.first < ptrs.second) {
            switch (compare_target_sum(ptrs, target, nums)) {
                case SumCompare::Equal:
                    res.push_back(ptrs);
                    shrink_left(ptrs, nums);
                    break;
                case SumCompare::Low:
                    shrink_left(ptrs, nums);
                    break;
                case SumCompare::High:
                    shrink_right(ptrs,nums);
                    break;
            }
        }
        return res;
    }
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3) return {};
        std::ranges::sort(nums);
        vector<vector<int>> three_sum_values;
        
        for (TwoPointer i{0, nums.size() - 2}; i.first < i.second;) {
            const int target = -1 * nums[i.first];
            const TwoPointer two_sum_span{i.first + 1, nums.size() - 1};
            
            if (auto two_sum = two_sum_2(two_sum_span, target, nums); !two_sum.empty()) {
                
                for (const auto& [left, right] : two_sum) {
                    three_sum_values.push_back({nums[i.first], nums[left], nums[right]});
                }
            }
            shrink_left(i, nums);
        }
        return three_sum_values;
        
    }
};
