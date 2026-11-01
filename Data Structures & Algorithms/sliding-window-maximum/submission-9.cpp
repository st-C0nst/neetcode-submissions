#include <deque>
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        std::deque<int> max_stack;
        std::vector<int> res;
        res.reserve(nums.size() - k);
        
        int l =0;
        for (int r = 0; r < nums.size(); ++r) {
            // if window grew too large, shrink left
            if (r - l + 1 > k) {
                ++l;
                if (!max_stack.empty() && max_stack.front() < l) {
                    max_stack.pop_front();
                }
            }
            
            
            while (!max_stack.empty() && nums[r] >= nums[max_stack.back()]) {
                max_stack.pop_back();
            }
            max_stack.push_back(r);

            // if the window size is of k, pushback a res
            if (r - l + 1 == k) {
                res.push_back(nums[max_stack.front()]);
            }
        }
        return res;
    }
};

// monotonic decreasing deque which always stores the monotonic decreasing range of values in the window
// basically like having a monotonic stack but we can slide it easily


// state
// track all max avlues and soon to be max values in the window
// invariant. max monotoonic deque must not exceed size of window
// I must also track the actual values that are in teh deque some how.. can this be derived?
// this cant be derived but the values can. so the deque can instead store the indexes then i just lookup to see the values
// we can remove duplicates
// transition
// we pop left and then push right. which should we do first.
// on a slide we first add some value
// whne we push right what must we do?
// we need to see if right larger or equal than any other values in monotonic decreasing stack, pop front. then push back
// when I pop left... how do I know if I remove from the deque. we store indexes then we pop while front index < new left
