#include <ranges>

class Solution {
public:
    using MinIndexEntry = std::pair<int,int>;
    using MonoStack = std::stack<MinIndexEntry>;
    int process_right_bound(int height, int right_bound, MonoStack& left_heights) {
        int max_area = 0;
        int left_pos = right_bound;
        while (!left_heights.empty() && height < left_heights.top().first) {
            left_pos = left_heights.top().second;
            
            int area = (right_bound - left_pos) * left_heights.top().first;
            max_area = max(area, max_area);
            left_heights.pop();
        }
        left_heights.push({height, left_pos});
        return max_area;
    }
    
    
    int largestRectangleArea(vector<int>& heights) {
        MonoStack left_heights;
        int max_area = 0;
        for (const auto& [index, h] : std::views::enumerate(heights)) {
            max_area = max(process_right_bound(h, index,left_heights), max_area);
        }

        max_area = max(process_right_bound(0, heights.size(), left_heights), max_area);
        return max_area;
    }
};


// 112224
// when we collapse some region because we found a new min in our monotonic stack, it indicates the end of some rectangle.
// the monotonic stack lets us grow until 
// when we pop we also update the start of some step
// if same size do nothing, 
// when we reach the end, consider that a step size of 0, thus process remaining stack with 0 as new value
// for every min we pop, we calc the rectangle based on the start min
// pop and form min stack as we iterate, a trough eliminates prev peaks
// on the stack store the min and the first index

// when curr < top, keep popping until we get smallest value, and keep tracking the current left index. before pushing, we take the index of last thing we popped and set that as curr index before pushing