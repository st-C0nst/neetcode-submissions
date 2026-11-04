#include <ranges>
#include <print>
class Solution {
public:
    static int max_subarray_sum(std::span<const int> nums) {
        int curr_sum = 0;
        int max_sum = 0;
        for (int i = nums.size() - 1; i >= 0; --i) {
            curr_sum += nums[i];
            if (curr_sum < 0) curr_sum = 0;
            max_sum = max(max_sum, curr_sum);
        }
        return max_sum;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        auto max_sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            std::ranges::rotate(nums, nums.end() - i);
            max_sum = std::max(max_sum, max_subarray_sum(nums));
        }
        return max_sum == 0? *std::ranges::max_element(nums) : max_sum;
    }
};
