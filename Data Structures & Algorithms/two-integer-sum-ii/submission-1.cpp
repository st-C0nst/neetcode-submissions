#include <utility>
class Solution {
public:
    using TwoPointers = std::pair<int,int>;

    inline TwoPointers shrink(const vector<int>& numbers, TwoPointers ptrs, int sum, int target) const {
        if (sum > target) {
            auto right = shrink_right(ptrs.second, numbers);
            return {ptrs.first, right};
        }
        else {
            auto left = shrink_left(ptrs.first, numbers);
            return {left, ptrs.second};
        }
    }
    
    inline int shrink_left(int left, const vector<int>& numbers) const {
        ++left;
        while (numbers[left] == numbers[left - 1]) {
            ++left;
        }
        return left;
    }
    
    inline int shrink_right(int right, const vector<int>& numbers) const {
        --right;
        while (numbers[right] == numbers[right + 1]) {
            --right;
        }
        return right;
    }
    TwoPointers find_two_sum(const vector<int>& numbers, TwoPointers ptrs, int target) const {
        while (true) {
            const auto [left, right] = ptrs;
            const int sum = numbers[left] + numbers[right];
            if (sum == target) {
                return ptrs;
            } else {
                ptrs = shrink(numbers, ptrs, sum, target);
            }
        }
        
    }
    vector<int> twoSum(vector<int>& numbers, int target) {
        auto [left, right] = find_two_sum(numbers, TwoPointers{0, numbers.size() - 1}, target);
        return {left + 1, right + 1};
    }
};
