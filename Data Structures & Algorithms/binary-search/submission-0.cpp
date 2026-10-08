class Solution {
public:
    using TwoPointer = std::pair<int,int>;
    static std::optional<std::size_t> binary_search(std::span<const int> nums, const int target) {
        TwoPointer bounds{0, nums.size() - 1};

        while (is_valid(bounds)) {
            auto [l,r] = bounds;
            const auto mid = l + (r - l) / 2;
            const auto num = nums[mid];
            if (num == target) {
                return mid;
            }
            else if (num > target) {
                bounds.second = mid - 1;
            }
            else {
                bounds.first = mid + 1;
            }
        }
        return {};
    }

    
    static bool is_valid(const TwoPointer bounds) {
        auto [l, r] = bounds;
        return l <= r;
    }
    int search(vector<int>& nums, int target) {
        auto res = binary_search(nums,target);
        if (!res) return -1;
        return res.value();
    }
};
