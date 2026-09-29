#include <unordered_map>
#include <ranges>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int,int> index_by_num;
        for (int index = 0; index < nums.size(); ++index) {
            const int n = nums[index];
            const auto compliment = target - n;
            if (auto comp_it = index_by_num.find(compliment); comp_it != index_by_num.end()) {
                return {comp_it->second, static_cast<int>(index)};
            }

            index_by_num[n] = index;
        }
        return {-1, -1};
    }
};
