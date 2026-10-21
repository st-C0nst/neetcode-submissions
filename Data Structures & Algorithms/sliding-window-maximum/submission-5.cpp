#include <vector>
#include <deque>
#include <ranges>

class Solution {
public:
    using Key = std::pair<int, int>;
    using WindowHeap = set<Key, std::greater<>>;
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dec_win;
        int l = 0;
        vector<int> res;
        int window_len = 0;
        for (int r = 0; r < nums.size(); ++r) {
            while (!dec_win.empty() && nums[r] > nums[dec_win.back()]) {
                dec_win.pop_back();
            }
            
            dec_win.push_back(r);
            
            while (l > dec_win.front()) {
                dec_win.pop_front();
            }
            
            if (r >= k - 1) {
                res.push_back(nums[dec_win.front()]);
                ++l;
            }
            
        }
        return res;
    }
};
