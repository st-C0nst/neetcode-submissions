#include <print>
class Solution {
public:
    using TwoPointer = std::pair<int,int>;
    static std::size_t find_upper_range(const vector<vector<int>>& matrix, int target) {
        const auto n = matrix.size();
        TwoPointer bounds{0, n};
        
        while (bounds.first < bounds.second) {
            auto& [l, r] = bounds;
            int mid = l + (r - l) / 2;

            if (matrix[mid][0] > target) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        return bounds.first;
    }
    
    static std::optional<std::size_t> binary_search(std::span<const int> nums, const int target) {
        TwoPointer bounds{0, nums.size() - 1};

        while (bounds.first <= bounds.second) {
            auto& [l,r] = bounds;
            const int mid = l + (r - l) / 2;
            const int num = nums[mid];
            if (num == target) {
                return mid;
            }
            else if (num > target) {
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return {};
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        auto upper_range = find_upper_range(matrix, target);
        if (upper_range == 0) return false;
        auto res = binary_search(matrix[upper_range - 1], target);
        
        return res.has_value();
    }
};