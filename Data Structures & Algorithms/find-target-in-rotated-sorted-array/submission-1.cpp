#include <ranges>

class Solution {
public:
    static std::optional<std::size_t> split_search(std::span<const int> nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        while (l <= r) {
            const int mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            
            // in right slice 
            if (nums[mid] < nums[0]) {
                if (nums[mid] > target) {
                    r = mid - 1;
                }
                else if (target > nums[r]) {
                    r = mid - 1;
                }
                else {
                    l = mid + 1;
                }
            }
            // in left slice
            else {
                if (nums[mid] < target) {
                    l = mid + 1;
                }
                else if (target < nums[l]) {
                    l = mid + 1;
                }
                else {
                    r = mid - 1;
                }
            }
        }
        return {};
    }
    int search(vector<int>& nums, int target) {

        auto index = split_search(nums, target);
        if (index) {
            return index.value();
        }
        return -1;
    }
};
