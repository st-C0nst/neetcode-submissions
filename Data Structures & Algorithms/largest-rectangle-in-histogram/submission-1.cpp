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