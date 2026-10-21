#include <vector>
#include <map>
#include <ranges>

class Solution {
public:
    using Key = std::pair<int, int>;
    using WindowHeap = map<Key, int, std::greater<>>;
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.size() <= k) {
            return {*std::ranges::max_element(nums)};
        }
        vector<int> maxes;
        maxes.reserve(nums.size() - k + 1);
        WindowHeap window_heap;

        // init window
        int l = 0;
        int r;

        for (int r = 0; r < nums.size(); ++r) {
            window_heap.emplace(Key{nums[r], r}, nums[r]);
            
            if (r - l + 1 > k) {
                window_heap.erase(Key{nums[l], l});
                ++l;
            }
            
            if (r-l + 1 ==k) {
                maxes.push_back(window_heap.begin()->second);
            }
        }
        
        return maxes;
    }
};

// init the window and process

// add r
// when we add r we should push to heap


// shrink l
// when we remove l.. we actually need to remove where it lives in the heap. thus we need a sorted map

// process get top from heap
