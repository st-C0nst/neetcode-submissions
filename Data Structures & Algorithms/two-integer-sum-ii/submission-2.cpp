#include <utility>

class Solution {
public:
    using TwoPointer = std::pair<int,int>;
    enum class Direction { Left, Right };
    template <Direction D>
    void shrink(TwoPointer& ptrs, const vector<int>& numbers) const {
        auto& [left, right] = ptrs;
        if constexpr (D == Direction::Left) {
            shrink_left(ptrs, numbers);
        }
        else {
            shrink_right(ptrs,numbers);
        }
    }
     
    enum class SumCompare { High, Low, Equal};
    SumCompare compare_to_target(const TwoPointer ptrs, const vector<int>& numbers, int target) const {
        const auto [left, right] = ptrs;
        const int sum = numbers[left] + numbers[right];
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
    
    vector<int> twoSum(vector<int>& numbers, int target) {
        TwoPointer ptrs{0, numbers.size() - 1};

        while (ptrs.first < ptrs.second) {
            switch (compare_to_target(ptrs, numbers, target)) {
                case SumCompare::Equal:
                    return {ptrs.first + 1, ptrs.second + 1};
                case SumCompare::Low:
                    shrink<Direction::Left>(ptrs, numbers);
                    break;
                case SumCompare::High:
                    shrink<Direction::Right>(ptrs, numbers);
                    break;
            }
        }
        std::unreachable();
    }
    private:
        void shrink_left(TwoPointer& ptrs, const vector<int>& numbers) const {
            auto& [left, right] = ptrs;
            ++left;
            while (left < right && numbers[left] == numbers[left - 1]) {
                ++left;
            }
        }
        
        void shrink_right(TwoPointer& ptrs, const vector<int>& numbers) const {
            auto& [left, right] = ptrs;
            --right;
            while (left < right && numbers[right] == numbers[right + 1]) {
                --right;
            }
        }
};
