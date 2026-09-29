#include <unordered_set>

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> visited;
        for (const auto& n : nums) {
            if (visited.contains(n)) {
                return true;
            }
            visited.insert(n);
        }
        return false;
    }
};